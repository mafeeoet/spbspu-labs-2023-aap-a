#include "makeLowerCaseString.h"
#include <cstddef>
#include <cctype>

char *shabalin::makeLowerCaseString(char *str, char *result)
{
  if (str == nullptr || *str == '\0')
  {
    return 0;
  }
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    if (std::isupper(str[i]))
    {
      str[i] = std::tolower(str[i]);
    }
  }
  for (size_t j = 0; str[j] != '\0'; ++j)
  {
    result[j] = str[j];
  }
  return result;
}
