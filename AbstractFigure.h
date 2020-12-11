#pragma once

#include <QPair>
#include <QPoint>

class AbstractFigure {
    public:
        enum class FigureType { Undefined, Circle, Rectangle };

        AbstractFigure(const QPoint& center): center_(center) {}
        virtual ~AbstractFigure() = default;

        QPoint GetCenter() const {return center_; }

        virtual FigureType GetType() const = 0;
        bool virtual IsDotInFigure(const QPoint& coordinates) const = 0;
    protected:
        QPoint center_;

};
