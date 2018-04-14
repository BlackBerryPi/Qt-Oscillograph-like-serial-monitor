#include "oscilloscope.h"
#include "ui_oscilloscope.h"

#include <QPainter>

Oscilloscope::Oscilloscope(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Oscilloscope)
{
    ui->setupUi(this);

    m_points.push_back(0);
    //QVector<>.mid();
    m_curr++;
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
        m_curr++;
        m_top++;
    }
    else
    {
        m_points.remove(0);
        m_points.push_back(point);
    }

    update();
}

void Oscilloscope::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    QPen pen;

    pen.setColor(QColor(66, 207, 227));
    pen.setWidth(2);

}
