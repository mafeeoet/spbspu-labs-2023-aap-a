#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <fstream>

namespace rebdev
{
  void filling(long long int * array, long long int rows,
    long long int colums, std::ifstream & inputFile);
  long long int localMax(long long int * arr, long long int rows, long long int colums);
}
#endif
