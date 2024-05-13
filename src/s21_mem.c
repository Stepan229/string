#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = s21_NULL;
  const unsigned char *p = str;
  for (s21_size_t i = 0; i < n; i++) {
    if (*(p + i) == (unsigned char)c) {
      res = (void *)(p + i);
      break;
    }
  }
  return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  for (s21_size_t i = 0; i < n && res == 0; ++i) {
    res = *((char *)str1 + i) - *((char *)str2 + i);
  }
  return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; ++i) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ptr = str;
  while (n--) {
    *ptr++ = (unsigned char)c;
  }
  return str;
}