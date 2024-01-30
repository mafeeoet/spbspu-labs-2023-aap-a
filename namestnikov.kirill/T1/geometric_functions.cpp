#include "geometric_functions.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>

double namestnikov::getSizeOfLine(const point_t & p1, const point_t & p2)
{
  return std::sqrt(std::abs(p1.x - p2.x) * std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y) * std::abs(p1.y - p2.y));
}


double namestnikov::getAreaOfTriangle(const point_t & p1, const point_t & p2, const point_t & p3)
{
  double a = getSizeOfLine(p1, p2);
  double b = getSizeOfLine(p1, p3);
  double c = getSizeOfLine(p2, p3);
  double halfPerimetr = (a + b + c) / 2;
  return std::sqrt(halfPerimetr * (halfPerimetr - a) * (halfPerimetr - b) * (halfPerimetr - c));
}

namestnikov::point_t namestnikov::getIntersectionOfTwoLines(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4)
{
  double a1 = 0, b1 = 0, c1 = 0;
  double a2 = 0, b2 = 0, c2 = 0;
  fillLineCoefficients(p1, p2, a1, b1, c1);
  fillLineCoefficients(p3, p4, a2, b2, c2);
  if (a1 / a2 == b1 / b2)
  {
    throw std::invalid_argument("There is no intersection\n");
  }
  else
  {
    double x = 0, y = 0;
    double d = a1 * b2 - b1 * a2;
    double dx = c1 * b2 - c2 * b1;
    double dy = a1 * c2 - c1 * a2;
    x = dx / d;
    y = dy / d;
    return {x, y};
  }
}

bool namestnikov::checkIntersectionOfTwoLines(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4)
{
  point_t line1 = {p2.x - p1.x, p2.y - p1.y};
  point_t line2 = {p3.x - p1.x, p3.y - p1.y};
  point_t line3 = {p4.x - p1.x, p4.y - p1.y};
  if ((line1.x * line2.y - line1.y * line2.x) * (line1.x * line3.y - line1.y * line3.x) >= 0)
  {
    return false;
  }

  line1 = {p4.x - p3.x, p4.y - p3.y};
  line2 = {p1.x - p3.x, p1.y - p3.y};
  line3 = {p2.x - p3.x, p2.y - p3.y};
  if ((line1.x * line2.y - line1.y * line2.x) * (line1.x * line3.y - line1.y * line3.x) >= 0)
  {
    return false;
  }
  return true;
}

void namestnikov::fillLineCoefficients(const point_t & p1, const point_t & p2, double & a, double & b, double & c)
{
  if (p1.x == p2.x)
  {
    a = 1;
    b = 0;
    c = -p2.x;
  }
  else if (p1.y == p2.y)
  {
    a = 0;
    b = 1;
    c = -p2.y;
  }
  else
  {
    a = 1;
    b = (p2.x - p1.x) / (p1.y - p2.y);
    c = -p1.x * a - p1.y * b;
  }
}

void namestnikov::isoScale(Shape * shape, const point_t & point, double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaling coefficient must be greater than zero\n");
  }
  else
  {
    point_t oldCenterPoint = shape->getFrameRect().pos;
    shape->move(point);
    shape->scale(coefficient);
    point_t newCenterPoint = shape->getFrameRect().pos;
    double dx = (oldCenterPoint.x - newCenterPoint.x) * coefficient;
    double dy = (oldCenterPoint.y - newCenterPoint.y) * coefficient;
    shape->move(dx, dy);
  }
}

void namestnikov::deleteShapes(Shape ** shapes, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shapes[i];
  }
  delete [] shapes;
}
