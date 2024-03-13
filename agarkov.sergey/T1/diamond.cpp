#include "diamond.hpp"
#include <stdexcept>
#include <cmath>

agarkov::Diamond::Diamond(point_t point1, point_t point2, point_t center):
  point1_(point1),
  point2_(point2),
  center_(center)
{
  if (!isCorrectDiamond())
  {
    throw std::invalid_argument("Incorrect diamond argument");
  }
}

double agarkov::Diamond::getArea() const
{
  return (std::fabs(point2_.x_ - center_.x_)) * (std::fabs(point1_.y_ - center_.y_)) * 2;
}

agarkov::rectangle_t agarkov::Diamond::getFrameRectangle() const
{
  return {center_, (std::fabs(point2_.x_ - center_.x_)) * 2, (std::fabs(point1_.y_ - center_.y_)) * 2};
}

void agarkov::Diamond::move(double dx, double dy)
{
  point1_.move(dx, dy);
  point2_.move(dx, dy);
  center_.move(dx, dy);
}

void agarkov::Diamond::move(agarkov::point_t position)
{
  double dx = position.x_ - center_.x_;
  double dy = position.y_ - center_.y_;
  move(dx, dy);
}

void agarkov::Diamond::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale coefficient");
  }
  point1_.unsaveScale(center_, k);
  point2_.unsaveScale(center_, k);
}

bool agarkov::Diamond::isCorrectDiamond() const
{
  return (center_.x_ == point1_.x_) && (center_.y_ == point2_.y_);
}
