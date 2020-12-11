#pragma once

#include "AbstractFigure.h"

class Circle: public AbstractFigure {
    public:
        Circle(const QPoint& center, int radius);

        int GetRadius() const {return radius_; }

        FigureType GetType() const final {return FigureType::Circle; }
        bool IsDotInFigure(const QPoint& coordinates) const final;
    private:
        int radius_;
};
