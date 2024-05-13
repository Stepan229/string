#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  if (str == s21_NULL)
    len = 0;
  else {
    while (str[len] != 0) {
      len++;
    }
  }
  return len;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n; ++i) {
    if (str1[i] == 0 || str1[i] != str2[i]) {
      result = str1[i] - str2[i];
      break;
    }
  }
  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t haystack_len = s21_strlen(haystack);
  s21_size_t needle_len = s21_strlen(needle);
  char *result = s21_NULL;
  if (needle_len == 0) {
    result = (char *)haystack;
  } else if (haystack_len >= needle_len) {
    for (s21_size_t i = 0; i < haystack_len; ++i) {
      if (s21_strncmp(haystack + i, needle, needle_len) == 0) {
        result = (char *)(haystack + i);
        break;
      }
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  s21_size_t index = s21_strlen(str);
  for (s21_size_t i = index; i > 0; --i) {
    if (str[i] == c) {
      result = (char *)(str + i);
      break;
    }
  }
  return result;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  s21_size_t str1_index = s21_strlen(str1);
  s21_size_t str2_index = s21_strlen(str2);
  for (s21_size_t i = 0; i < str1_index; ++i) {
    for (s21_size_t j = 0; j < str2_index; ++j) {
      if (str1[i] == str2[j]) {
        result = (char *)(str1 + i);
        break;
      }
    }
    if (result != s21_NULL) {
      break;
    }
  }
  return result;
}

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  s21_size_t index = s21_strlen(str);
  for (s21_size_t i = 0; i < index; ++i) {
    if (str[i] == c) {
      result = (char *)(str + i);
      break;
    }
  }
  return result;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  s21_size_t str1_len = s21_strlen(str1);
  s21_size_t str2_len = s21_strlen(str2);
  int status = 1;
  for (s21_size_t i = 0; i < str1_len; ++i) {
    for (s21_size_t j = 0; j < str2_len; ++j) {
      if (str1[i] == str2[j]) {
        status = 0;
        break;
      }
    }
    if (status) {
      count++;
    } else {
      break;
    }
  }
  return count;
}
char *s21_strtok(char *str, const char *delim) {
  static char *token_ptr = s21_NULL;
  char *token_start = s21_NULL;
  int flag = 1;
  static int exist_non_delim_chars = 0;
  if (str != s21_NULL) {
    token_ptr = str;
    exist_non_delim_chars = 0;
  } else if (token_ptr == s21_NULL) {
    flag = 0;
  }

  if (token_ptr != s21_NULL && s21_strchr(delim, *token_ptr) != s21_NULL) {
    exist_non_delim_chars = 0;
  }

  while (exist_non_delim_chars == 0) {
    if (token_ptr != s21_NULL && s21_strchr(delim, *token_ptr) != s21_NULL) {
      token_ptr++;
    } else {
      exist_non_delim_chars = 1;
    }
  }
  if (flag) {
    token_start = token_ptr;
    char *token_end = s21_strpbrk(token_start, delim);

    if (token_end != s21_NULL) {
      *token_end = '\0';
      token_ptr = token_end + 1;
    } else {
      if (*token_start == 0) {
        token_start = s21_NULL;
      }
      token_ptr = s21_NULL;
    }
  }
  return token_start;
}

char *s21_strcpy(char *dest, char *source) {
  char *tmp = dest;
  while (*source != 0) {
    *dest++ = *source++;
  }
  *dest = 0;
  return tmp;
}

char *s21_strncat(char *destination, const char *source, s21_size_t n) {
  s21_size_t lenDest = s21_strlen(destination);
  s21_size_t i = 0;
  while (i < n && i < s21_strlen(source)) {
    destination[lenDest + i] = source[i];
    i++;
  }
  destination[lenDest + i] = '\0';
  return destination;
}

char *s21_strncpy(char *destination, const char *source, s21_size_t n) {
  if (n > s21_strlen(source)) {
    for (s21_size_t i = 0; i < n && destination[i] != '\0'; i++) {
      if (i < s21_strlen(source))
        destination[i] = source[i];
      else
        destination[i] = '\0';
    }
  } else {
    for (s21_size_t i = 0; source[i] != '\0' && i < n; i++) {
      destination[i] = source[i];
    }
  }
  return destination;
}

char *s21_strcat(char *destination, const char *source) {
  int i = 0, j = 0;
  while (destination[i] != '\0') i++;
  while (source[j] != '\0') {
    destination[i] = source[j];
    i++;
    j++;
  }
  return (char *)destination;
}