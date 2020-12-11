#pragma once
#include "AbstractFigure.h"


class FiguresFactory {
    public:
        static std::shared_ptr<AbstractFigure> GetRandomFigure(const QPoint& center);

    private:
        static AbstractFigure::FigureType GetRandomType();
        static std::shared_ptr<AbstractFigure> GetRandomCircle(const QPoint& center);
        static std::shared_ptr<AbstractFigure> GetRandomRectangle(const QPoint& center);

        static constexpr int max_radius = 50;
        static constexpr int max_height = 50;
        static constexpr int max_width = 50;
};
