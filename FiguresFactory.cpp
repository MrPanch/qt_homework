#include <QRandomGenerator>
#include "FiguresFactory.h"
#include "Circle.h"
#include "Rectangle.h"

std::shared_ptr<AbstractFigure> FiguresFactory::GetRandomFigure(const QPoint& center) {
    auto type = GetRandomType();

    if (type == AbstractFigure::FigureType::Circle) {
        return GetRandomCircle(center);
    } else if (type == AbstractFigure::FigureType::Rectangle) {
        return GetRandomRectangle(center);
    }

    return nullptr;
}

AbstractFigure::FigureType FiguresFactory::GetRandomType() {
    int value = QRandomGenerator::global()->generate() % 2;

    if (value == 0) {
        return AbstractFigure::FigureType::Circle;
    }

    return AbstractFigure::FigureType::Rectangle;
}

std::shared_ptr<AbstractFigure> FiguresFactory::GetRandomCircle(const QPoint& center) {
    int radius = QRandomGenerator::global()->generate() % max_radius;

    return std::make_shared<Circle>(center, radius);
}

std::shared_ptr<AbstractFigure> FiguresFactory::GetRandomRectangle(const QPoint &center) {
    int width = QRandomGenerator::global()->generate() % max_width;
    int height = QRandomGenerator::global()->generate() % max_height;

    return std::make_shared<Rectangle>(center, width, height);
}

