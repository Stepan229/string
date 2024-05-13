#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *out = s21_NULL;
  s21_size_t str_len = 0;
  s21_size_t out_len = 0;
  if (str != s21_NULL) {
    str_len = s21_strlen(str);
  }
  if (src != s21_NULL && (start_index <= s21_strlen(src))) {
    out_len = str_len + s21_strlen(src);
    out = (char *)calloc(out_len + 1, sizeof(char));
  }
  if (out != s21_NULL) {
    for (s21_size_t i = 0; i < out_len; ++i) {
      if (i >= start_index && *str) {
        out[i] = *(str++);
      } else {
        out[i] = *(src++);
      }
    }
    out[out_len] = '\0';
  }
  return out;
}
