#ifndef OSCILLOSCOPE_H
#define OSCILLOSCOPE_H

#include <QWidget>
#include <QPainter>

#define MAXIMUM 10000

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

private:
    QVector<int> m_points;
    int m_top = 0;
    int m_curr = 0;
};

#endif // OSCILLOSCOPE_H
