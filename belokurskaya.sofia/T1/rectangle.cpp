#include <stdexcept>

#include "rectangle.hpp"
#include "base-types.hpp"

belokurskaya::Rectangle::Rectangle(const point_t & lower_left, const point_t & upper_right):
  lower_left_(lower_left), upper_right_(upper_right)
{
  if (lower_left_.x >= upper_right_.x || lower_left_.y >= upper_right_.y)
  {
    throw std::invalid_argument("Invalid rectangle dimensions");
  }
}

double belokurskaya::Rectangle::getArea() const
{
  return (upper_right_.x - lower_left_.x) * (upper_right_.y - lower_left_.y);
}

belokurskaya::rectangle_t belokurskaya::Rectangle::getFrameRect() const
{
  double width = upper_right_.x - lower_left_.x;
  double height = upper_right_.y - lower_left_.y;
  point_t center = {upper_right_.x - (width / 2), upper_right_.y - (height / 2)};
  return {center, width, height};
}

void belokurskaya::Rectangle::move(const point_t & new_pos)
{
  point_t center = getFrameRect().pos;
  move(new_pos.x - center.x, new_pos.y - center.y);
}

void belokurskaya::Rectangle::move(double dx, double dy)
{
  lower_left_.x += dx;
  lower_left_.y += dy;
  upper_right_.x += dx;
  upper_right_.y += dy;
}

void belokurskaya::Rectangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Invalid scaling factor");
  }
  rectangle_t frameRect = getFrameRect();
  point_t old_center = frameRect.pos;
  double width = frameRect.width;
  double height = frameRect.height;

  width *= factor;
  height *= factor;

  lower_left_.x = old_center.x - width / 2;
  lower_left_.y = old_center.y - height / 2;
  upper_right_.x = old_center.x + width / 2;
  upper_right_.y = old_center.y + height / 2;
}

belokurskaya::Shape::ShapeType belokurskaya::Rectangle::getShapeType()
{
  return belokurskaya::Shape::RECTANGLE;
}
