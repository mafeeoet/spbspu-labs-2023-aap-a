#include "searchLines.hpp"

size_t isaychev::searchLines(int * matrix, size_t rs, size_t cs)
{
  size_t lineCount = 0;
  if (cs != 1)
  {
    size_t countEq = 0;
    for (size_t i = 0; i < rs*cs-1; ++i)
    {
      int currElement = matrix[i];
      int nextElement = matrix[i+1];
      if (currElement == nextElement)
      {
        ++countEq;
      }
      if (((i + 1) % (cs - 1)) == 0)
      {
        if(countEq == 0)
        {
          ++lineCount;
        }
        countEq = 0;
        ++i;
      }
    }
  }
  else if (cs == 1)
  {
    lineCount = rs;
  }
  return lineCount;
}
