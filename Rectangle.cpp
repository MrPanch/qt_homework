#include "Rectangle.h"

Rectangle::Rectangle(const QPoint& center, int width, int height):
    AbstractFigure(center),
    width_(width),
    height_(height)
{}

bool Rectangle::IsDotInFigure(const QPoint& coordinates) const {
    return coordinates.x() >= (center_.x() - width_ / 2.0) &&
            coordinates.x() <= (center_.x() + width_ / 2.0) &&
            coordinates.y() >= (center_.y() - height_ / 2.0) &&
            coordinates.y() <= (center_.y() + height_ / 2.0);
}
