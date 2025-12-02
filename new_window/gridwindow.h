#ifndef GRIDWINDOW_H
#define GRIDWINDOW_H

#include <QObject>

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

class GridWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GridWindow(QWidget *parent = nullptr);

signals:

private:
    QVector <QPushButton*> ch_btns_vector;
    QVector <int> ch_btns_state;


};

#endif // GRIDWINDOW_H
