#pragma once

#include <QMainWindow>
#include "Representer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        explicit MainWindow(QWidget* parent = nullptr);
        ~MainWindow();

    private:
        void UpdateHandler();
        void paintEvent(QPaintEvent* paint_event) override;
        void mousePressEvent(QMouseEvent* mouse_event) override;

        Ui::MainWindow* ui_;

        Representer representer_;
};
