#include "Representer.h"
#include "Circle.h"
#include "Rectangle.h"
#include "FiguresFactory.h"

void Representer::AddRandomFigure(const QPoint& coordinates) {
    auto newFigure = FiguresFactory::GetRandomFigure(coordinates);
    figures_.append(newFigure);

    emit Updated();
}

void Representer::DeleteFigure(const QPoint& coordinates) {
    figures_.erase(std::remove_if(figures_.begin(), figures_.end(),
                                  [coordinates](std::shared_ptr<AbstractFigure> figure) {
                       return figure->IsDotInFigure(coordinates);
                   }), figures_.end());

    emit Updated();
}

void Representer::Repaint(QPaintDevice* device) {
    painter_.begin(device);
    for (const auto& figure : figures_) {
        if (figure->GetType() == AbstractFigure::FigureType::Circle) {
            DrawCircle(std::dynamic_pointer_cast<Circle>(figure));
        } else if (figure->GetType() == AbstractFigure::FigureType::Rectangle) {
            DrawRectangle(std::dynamic_pointer_cast<Rectangle>(figure));
        }
    }
    painter_.end();
}

void Representer::DrawCircle(std::shared_ptr<Circle> circle) {
    painter_.drawEllipse(circle->GetCenter(), circle->GetRadius(), circle->GetRadius());
}

void Representer::DrawRectangle(std::shared_ptr<Rectangle> rectangle) {
    auto rectangleCenter = rectangle->GetCenter();
    painter_.drawRect(rectangleCenter.x() - rectangle->GetWitdth() / 2 ,
                      rectangleCenter.y() - rectangle->GetHeight() / 2,
                      rectangle->GetWitdth(), rectangle->GetHeight());

}
