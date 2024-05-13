#include "s21_string.h"

char *s21_to_upper(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;  // передана нулевая строка
  }

  s21_size_t len = s21_strlen(str);
  char *result = (char *)malloc(len + 1);  // +1 для '\0'

  if (result == s21_NULL) {
    return s21_NULL;  // не удалось выделить память
  }

  for (s21_size_t i = 0; i < len; ++i) {
    result[i] =
        (str[i] >= 'a' && str[i] <= 'z') ? (str[i] - 'a' + 'A') : str[i];
  }

  result[len] = '\0';

  return result;

  // free после возвр
}
