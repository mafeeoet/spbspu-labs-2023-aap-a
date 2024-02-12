#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace zaitsev
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(point_t vertex1, point_t vertex2, point_t vertex3);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& dest_pos);
    virtual void move(double x_shift, double y_shift);
    virtual void scale(double factor);
  private:
    point_t def_vertices_[3];
    point_t getCenter() const;
  };
}
#endif
