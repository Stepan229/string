#include "s21_string.h"

char *s21_to_lower(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t len = s21_strlen(str);
  char *result = (char *)malloc(len + 1);

  if (result == s21_NULL) {
    return s21_NULL;
  }

  for (s21_size_t i = 0; i < len; ++i) {
    result[i] =
        (str[i] >= 'A' && str[i] <= 'Z') ? (str[i] - 'A' + 'a') : str[i];
  }

  result[len] = '\0';

  return result;

  // free mem res
}
