#pragma once

#include <QPainter>
#include <QVector>
#include <memory>

#include "Circle.h"
#include "Rectangle.h"


class Representer : public QObject {
    Q_OBJECT
    public:
        Representer() = default;

        void AddRandomFigure(const QPoint& coordinates);
        void DeleteFigure(const QPoint& coordinates);

        void Repaint(QPaintDevice* device);

        Q_SIGNAL void Updated();
    private:
        void DrawCircle(std::shared_ptr<Circle> circle);
        void DrawRectangle(std::shared_ptr<Rectangle> rectangle);

        QPainter painter_;

        QVector<std::shared_ptr<AbstractFigure>> figures_;
};
