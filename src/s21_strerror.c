#include "s21_strerror.h"

#include "s21_string.h"

char* s21_strerror(int errnum) {
  static char res[128] = {0};
  if (errnum > MAX_ERROR || errnum < MIN_ERROR) {
#ifdef __APPLE__
    s21_sprintf(res, "Unknown error: %d", errnum);
#elif __linux__
    s21_sprintf(res, "Unknown error %d", errnum);
#endif
  } else {
    s21_sprintf(res, "%s", error_list[errnum]);
  }

  return res;
}