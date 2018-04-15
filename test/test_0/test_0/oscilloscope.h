#ifndef OSCILLOSCOPE_H
#define OSCILLOSCOPE_H

#include <QWidget>
#include <QPainter>

#define MAXIMUM 100000

namespace Ui {
class Oscilloscope;
}

class Oscilloscope : public QWidget
{
    Q_OBJECT

public:
    explicit Oscilloscope(QWidget *parent = 0);
    ~Oscilloscope();
    
    void setData(int point);

private:
    Ui::Oscilloscope *ui;

protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);

public slots:
    void on_resolutionChanged(int x_str, int y_str, int x_move, int y_move);

private slots:
    void on_checkFollow_stateChanged(int arg1);

private:
    QVector<int> m_points;
    int m_top = 0;
    int m_curr = 0;
    int m_min = 0;
    int m_max = 0;
    bool m_follow = true;
    int x_resolution;
    int y_resolution;
    int x_base = 0;                         //X偏移
    int y_base = 0;                         //Y偏移

    qint64 m_initTime = 0;
    qint64 m_currTime = 0;
};

#endif // OSCILLOSCOPE_H
