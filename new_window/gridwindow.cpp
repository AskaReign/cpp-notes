#include "gridwindow.h"

GridWindow::GridWindow(QWidget *parent) : QWidget(parent)
{
    auto *mainLayout = new QVBoxLayout(this);

    auto *gridLayout = new QGridLayout(this);
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->setSpacing(0);

    int rows = 17;
    int cols = 13;

    int start = 8500;

    ch_btns_vector.reserve(221);

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            auto *btn = new QPushButton(QString("%1").arg(start));
            gridLayout->addWidget(btn, r, c);

            ch_btns_vector.push_back(btn);

            btn->setStyleSheet("background-color: rgb(111, 194, 118)");

            start += 5;
        }
    }

    ch_btns_state.resize(221);
    for (int i = 0; i < 221; i++) {
        ch_btns_state[i] = 1;
    }

    for (int i = 0; i < 221; i++) {
        QPushButton* button = ch_btns_vector[i];

        QObject::connect(button, &QPushButton::clicked, [this, button, i]() {
            QString currentStyle = button->styleSheet();

            if (currentStyle.contains("red")) {
                button->setStyleSheet("background-color: rgb(111, 194, 118)");
                ch_btns_state[i] = 1;

            } else {
                button->setStyleSheet("background-color: red");
                ch_btns_state[i] = 0;
            }

        });
    }

    mainLayout->addLayout(gridLayout);
    setLayout(mainLayout);
    setWindowTitle("Channel Select");

//    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
}

