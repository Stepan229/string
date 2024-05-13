#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  char *processed_trim_chars = s21_NULL;
  if (s21_strlen(trim_chars) == 0) {
    processed_trim_chars = malloc(2 * sizeof(char));
    processed_trim_chars[0] = ' ';
    processed_trim_chars[1] = '\0';
  } else {
    processed_trim_chars = malloc(sizeof(trim_chars));
    s21_strcpy(processed_trim_chars, (char *)trim_chars);
  }

  if (src != s21_NULL) {
    s21_size_t right_side_index_to_cut = 0;
    s21_size_t left_side_index_to_cut = 0;
    s21_size_t src_len = s21_strlen(src);

    for (s21_size_t i = 0;
         i < src_len && s21_strchr(processed_trim_chars, src[i]); ++i) {
      left_side_index_to_cut++;
    }

    for (s21_size_t i = src_len - 1;
         i > 0 && s21_strchr(processed_trim_chars, src[i]); --i) {
      right_side_index_to_cut++;
    }

    int res_len = src_len - (right_side_index_to_cut + left_side_index_to_cut);
    if (res_len < 0) {
      res_len = 0;
    }
    res = calloc(res_len + 1, sizeof(char));
    if (res != s21_NULL) {
      for (int i = 0; i < res_len; ++i) {
        res[i] = src[left_side_index_to_cut++];
      }
    }
  }
  free(processed_trim_chars);
  return res;
}