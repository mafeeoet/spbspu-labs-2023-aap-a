#include "diamond.hpp"

agarkov::Diamond::Diamond(point_t point1, point_t point2, point_t center):
  point1_(point1),
  point2_(point2),
  center_(center)
{
}

double agarkov::Diamond::getArea() const
{
  return (std::fabs(point2_.x_ - center_.x_)) * (std::fabs(point1_.y_ - center_.y_)) * 2;
}

agarkov::rectangle_t agarkov::Diamond::getFrameRectangle()
{
  return {center_, (std::fabs(point2_.x_ - center_.x_)) * 2, (std::fabs(point1_.y_ - center_.y_)) * 2};
}

void agarkov::Diamond::move(double dx, double dy)
{
  point1_.move(dx);
  point2_.move(dx);
  center_.move(dx);
}

void agarkov::Diamond::move(agarkov::point_t position)
{
  double dx = position.x_ - centre_.x_;
  double dy = position.y_ - centre_.y_;
  move(dx, dy);
}

