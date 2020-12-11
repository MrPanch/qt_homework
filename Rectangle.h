#pragma once

#include "AbstractFigure.h"

class Rectangle: public AbstractFigure {
    public:
        Rectangle(const QPoint& center, int width, int height);

        int GetWitdth() const {return width_; }
        int GetHeight() const {return height_; }

        FigureType GetType() const final {return FigureType::Rectangle; }
        bool IsDotInFigure(const QPoint& coordinates) const final;
    private:
        int width_;
        int height_;

};
