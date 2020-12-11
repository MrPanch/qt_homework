#include "Circle.h"

Circle::Circle(const QPoint& center, int radius)
    : AbstractFigure(center), radius_(radius) {}

bool Circle::IsDotInFigure(const QPoint& coordinates) const {
    return ((coordinates.x() - center_.x()) *
                (coordinates.x() - center_.x()) +
            (coordinates.y() - center_.y()) *
                (coordinates.y() - center_.y())) <= radius_ * radius_;
}
