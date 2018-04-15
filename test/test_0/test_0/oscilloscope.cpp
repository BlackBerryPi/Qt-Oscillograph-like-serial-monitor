#include "oscilloscope.h"
#include "ui_oscilloscope.h"

#include <QPainter>
#include <QDebug>
#include <QDateTime>

Oscilloscope::Oscilloscope(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Oscilloscope)
{
    ui->setupUi(this);

    m_max = 255;

    m_initTime = QDateTime::currentMSecsSinceEpoch();

    m_points.push_back(0);
//    QVector<>.mid();
    m_curr++;

//    connect(ui->checkFollow, &QCheckBox::stateChanged, this, &Oscilloscope::on_checkFollow_stateChanged);
}

Oscilloscope::~Oscilloscope()
{
    delete ui;
}

void Oscilloscope::setData(int point)
{ 
    if(m_top < MAXIMUM)
    {
        m_points.push_back(point);
        if(m_follow)
        {
            m_curr++;
        }
        m_top++;
    }
    else
    {
        m_points.remove(0);
        m_points.push_back(point);
        if(!m_follow)
        {
            if(m_curr > 0)
            {
                m_curr--;
            }
        }
    }

    //qDebug() << "Painter: " << point;

    update();
}

void Oscilloscope::paintEvent(QPaintEvent *e)
{
    x_resolution = width();
    y_resolution = height();

    QPainter p(this);
    QPen pen;

    pen.setColor(QColor(66, 207, 227));
    pen.setWidth(2);
    p.setPen(pen);

    QVector<int> tempVector = m_points.mid(m_curr-x_resolution, x_resolution+5);

    int step = ceil(((double)width())/x_resolution);
    if(step <= 0)
    {
        step = 1;
    }

    int x = -step;

    /*
    m_min = *(tempVector.begin());
    m_max = *(tempVector.begin());

    for(QVector<int>::iterator it=tempVector.begin(); it!=tempVector.end(); it++)
    {
        if(m_max < *it)
             m_max = *it;

        if(m_min > *it)
             m_min = *it;
    }
    */

    for(QVector<int>::iterator it=tempVector.begin(); it!=tempVector.end(); it++)
    {
        p.drawLine(x, (1-((*it-m_min)/(double(m_max-m_min+30))))*y_resolution-30, x+step, (1-((*(it+1)-m_min)/(double(m_max-m_min+30))))*y_resolution-30);
        x += step;
    }
}

void Oscilloscope::resizeEvent(QResizeEvent *e)
{
    update();
}

void Oscilloscope::on_resolutionChanged(int x_str, int y_str, int x_move, int y_move)
{

}

void Oscilloscope::on_checkFollow_stateChanged(int arg1)
{
    m_follow = ui->checkFollow->checkState();
    m_curr = m_top;
    //qDebug() << "checkbox changed";
}
