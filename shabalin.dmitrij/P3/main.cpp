/*
#include <iostream>
#include <stdexcept>
#include "duplicateNumbers.h"
#include "makeLowerCaseString.h"
#include "inputOfString.h"

int main()
{
  using namespace shabalin;
  char *finalString = nullptr;
  try
  {
    finalString = inputOfString(std::cin);
    if (finalString[0] == '\0')
    {
      delete[] finalString;
      std::cerr << "Error" << "\n";
      return 1;
    }
    std::cout << duplicateNumbers(finalString) << "\n";
    char result[] = "123";
    std::cout << makeLowerCaseString(finalString, result) << "\n";
  }
  catch (const std::bad_alloc &e)
  {
    delete[] finalString;
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  delete[] finalString;
  return 0;
}
*/

#include <iostream>
#include <stdexcept>
#include "duplicateNumbers.h"
#include "makeLowerCaseString.h"
#include "inputOfString.h"

int main()
{
  using namespace shabalin;
  char *initialString = nullptr;
  // size_t initialSize = 10;

  try
  {
    initialString = inputOfString(std::cin, initialString);
    if (initialString[0] == '\0')
    {
      std::cerr << "Error\n";
      delete[] initialString;
      return 1;
    }
    std::cout << duplicateNumbers(initialString) << "\n";
    char result[] = "123";
    std::cout << makeLowerCaseString(initialString, result) << "\n";
    delete[] initialString;
    return 0;
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    delete[] initialString;
    return 1;
  }
}
