#include "sscanf.h"

int s21_sscanf(const char* str, const char* format, ...) {
  int result = 0;
  int status = 0;
  int format_index = 0;
  int str_index = 0;
  int flag = 0;
  char tmp_str[1024] = {0};
  token _format;
  _format.spaces = 0;
  _format.count_symb = 0;
  int str_len = (int)s21_strlen(str);
  int format_len = (int)s21_strlen(format);
  va_list ap;
  va_start(ap, format);
  if (str_len == 0 || check_str(str, str_len)) {
    result = -1;
  } else {
    while (format_index < format_len) {
      if (format[format_index] == ' ') {
        format_index++;
        _format.spaces = 1;
        continue;
      }
      if (format[format_index] == '%') {
        clear_token(&_format);
        format_index = parse_format(&_format, format, ++format_index);
        if (_format.spec == '%' && flag == 0) {
          get_percent(str, &str_index, &flag);
        } else if (flag == 0) {
          if (_format.asterisk != 1) {
            _format.arg = va_arg(ap, void*);
          }

          if (_format.spec != 'n') {
            str_index =
                engage_specifiers(str, tmp_str, &_format, str_index, &status);

            if (status) {
              result += status;
              s21_memset(_format.str_to_assign, 0,
                         s21_strlen(_format.str_to_assign));
            } else if (!status && _format.asterisk == 0) {
              flag = 1;
            }
          } else {
            symbol_count(&_format, str_index, (int)str_len, (int)format_len,
                         format_index);
            specifiers_process(&_format);
          }
          _format.spaces = 0;
        }
      } else {
        str_index =
            check_char(&_format, str, str_index, format[format_index], &flag);
        format_index++;
      }
      if (flag) {
        break;
      }
    }
  }
  va_end(ap);
  return result;
}

int check_str(const char* str, int str_len) {
  int result = 1;

  for (int i = 0; i < str_len; ++i) {
    if (isspace(str[i]) == 0) {
      result = 0;
      break;
    }
  }

  return result;
}

int s21_atoi(const char* str, int* index) {
  int result = 0;
  int sign = 1;
  int i = 0;

  while (str[i] == ' ') {
    i++;
  }

  if (str[i] == '-') {
    sign = -1;
    i++;
  } else if (str[i] == '+') {
    i++;
  }

  while (str[i] >= '0' && str[i] <= '9') {
    result = result * 10 + (str[i] - '0');
    i++;
  }
  *index += i;
  return sign * result;
}

void symbol_count(token* _format, int str_index, int str_len, int format_len,
                  int format_index) {
  if (_format->spaces == 1 && str_index != str_len) {
    _format->count_symb++;
  }
  if (format_index == format_len && _format->spaces == 1) {
    while (str_index < str_len - 1) {
      _format->count_symb++;
      str_index++;
    }
  }
}

int parse_format(token* _format, const char* format, int index) {
  if (format[index] == '*') {
    _format->asterisk = 1;
    index++;
  }
  if (format[index] >= '0' && format[index] <= '9') {
    _format->width = s21_atoi(&(format[index]), &index);
  }
  _format->width_const = _format->width;
  if (s21_strchr("hlL", format[index])) {
    _format->length = format[index];
    index++;
    if (s21_strchr("l", format[index]) &&
        s21_strchr("diuoxX", format[index + 1])) {
      _format->length = 'L';
      index++;
    }
  }
  if (s21_strchr("cdieEfgGosuxXpn%", format[index])) {
    _format->spec = format[index];
    index++;
  }

  return index;
}

void clear_token(token* _format) {
  _format->arg = s21_NULL;
  _format->asterisk = 0;
  _format->width = -1;
  _format->length = 0;
  _format->spec = 0;
  _format->width_const = 0;
}

void get_percent(const char* str, int* str_index, int* flag) {
  while (s21_strchr(" \n\t\r\v\f", str[*str_index])) {
    *str_index += 1;
  }
  if (str[*str_index] != '%') {
    *flag = 1;
  } else {
    *str_index += 1;
  }
}

int engage_specifiers(const char* str, char* tmp_str, token* _format,
                      int str_index, int* status) {
  s21_memset(tmp_str, '0', s21_strlen(tmp_str));
  str_index = str_divide(str, tmp_str, _format, str_index);
  if (_format->asterisk == 1) {
    *status = 0;
  } else {
    *status = specifiers_process(_format);
  }
  return str_index;
}

int str_divide(const char* str, char* tmp_str, token* _format, int str_index) {
  int width_f = 0;
  int break_f = 1;
  int tmp_str_index = 0;
  int uncert = 0;
  if (_format->width == 0 || _format->width == -1) {
    _format->width = 1;
    width_f = 1;
  }
  while (((_format->spec != 'c') || _format->spaces == 1) &&
         (isspace(str[str_index]) != 0 && str[str_index])) {
    str_index++;
    _format->count_symb++;
  }
  if (s21_strchr("dieEfgGouxXp", _format->spec) &&
      (str[str_index] == '+' || str[str_index] == '-')) {
    tmp_str[tmp_str_index] = str[str_index];
    if (width_f == 0) {
      _format->width--;
    }
    str_index++;
    tmp_str_index++;
  }
  while (str[str_index] && _format->width && break_f) {
    if (!check_number(str, tmp_str, _format, str_index, width_f, &uncert)) {
      break;
    }
    tmp_str[tmp_str_index] = str[str_index];
    tmp_str_index++;
    str_index++;
    _format->count_symb++;
    if (_format->spec == 'c' && _format->width_const == -1) {
      break_f = 0;
    }
    if (width_f == 0) {
      _format->width--;
    }
  }
  tmp_str[tmp_str_index] = '\0';
  if (uncert == -1) {
    s21_strcat(tmp_str, "inf");
    str_index += 3;
  } else if (uncert == 1) {
    s21_strcat(tmp_str, "nan");
    str_index += 3;
  }
  s21_strcpy(_format->str_to_assign, tmp_str);
  return str_index;
}

int check_number(const char* str, char* tmp_str, token* _format, int str_index,
                 int flag, int* uncert) {
  int status = 1;
  if (s21_strchr("dieEfgGouxXp", _format->spec) &&
      isdigit(str[str_index]) == 0) {
    if (s21_strchr("dou", _format->spec)) {
      status = 0;
    }
    if (!check_hex(_format, tmp_str, str[str_index], flag)) {
      status = 0;
    }
    if (!check_double(_format, tmp_str, str[str_index])) {
      status = 0;
    }
    if (s21_strchr("eEfgG", _format->spec) &&
        s21_strchr("iInN", str[str_index])) {
      int sub_result = check_inan(str, str_index);
      if (sub_result != 0) {
        *uncert = sub_result;
      }
      status = 0;
    }
    if (_format->spec == 'o' &&
        (str[str_index] == '8' || str[str_index] == '9')) {
      status = 0;
    }
  }
  if (_format->spec != 'c' && isspace(str[str_index])) {
    status = 0;
  }
  return status;
}

int check_hex(token* _format, char* tmp_str, char sym, int flag) {
  int status = 1;
  if (s21_strchr("ixXp", _format->spec) && !s21_strchr("xXaAbBcCdDeEfF", sym)) {
    status = 0;
  }
  if (s21_strchr("ixXp", _format->spec)) {
    if (s21_strchr("xX", sym) && (tmp_str[0] != '0' && tmp_str[1] != '0') &&
        (s21_strchr(tmp_str, 'x') || s21_strchr(tmp_str, 'X'))) {
      status = 0;
    }
    if (flag == 0 && (((tmp_str[0] == '-' || tmp_str[0] == '+') &&
                       _format->width_const < 4) ||
                      ((tmp_str[0] != '-' && tmp_str[0] != '+') &&
                       _format->width_const < 3))) {
      status = 0;
    }
  }
  if (s21_strchr("ip", _format->spec) && !s21_strchr("xX", sym)) {
    if ((tmp_str[0] != '0' || (tmp_str[1] != 'x' && tmp_str[1] != 'X')) &&
        (tmp_str[1] != '0' || (tmp_str[2] != 'x' && tmp_str[2] != 'X'))) {
      status = 0;
    }
  }
  return status;
}

int check_double(token* _format, char* tmp_str, char sym) {
  int status = 1;
  if (s21_strchr("eEfgG", _format->spec)) {
    if (!s21_strchr("eE.+-", sym)) {
      status = 0;
    }
    if (s21_strchr("eE", sym) &&
        (s21_strchr(tmp_str, 'e') || s21_strchr(tmp_str, 'E'))) {
      status = 0;
    }
    if (sym == '.' && s21_strchr(tmp_str, '.')) {
      status = 0;
    }
  }
  return status;
}

int check_inan(const char* str, int str_index) {
  int status = 0;
  char tmp[4] = {0};
  int j = 0;
  for (int i = str_index; i < (str_index + 3); ++i) {
    if (str[i] <= 90 && str[i >= 65]) {
      tmp[j] = str[i];
    } else {
      tmp[j] = str[i] - 32;
    }
    ++j;
  }
  if (s21_strncmp(tmp, "INF", s21_strlen(tmp)) == 0) {
    status = -1;
  }
  if (s21_strncmp(tmp, "NAN", s21_strlen(tmp)) == 0) {
    status = 1;
  }
  return status;
}

int specifiers_process(token* _format) {
  int success_counter = 0;
  switch (_format->spec) {
    case 'd':
    case 'i':
      success_counter += process_di(_format);
      break;
    case 'o':
    case 'u':
    case 'x':
    case 'X':
      success_counter += process_ouxX(_format);
      break;
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      success_counter += process_efgEG(_format);
      break;
    case 'c':
      success_counter += process_c(_format);
      break;
    case 's':
      success_counter += process_s(_format);
      break;
    case 'p':
      success_counter += process_p(_format);
      break;
    case 'n':
      success_counter += process_n(_format);
      break;
    default:
      break;
  }
  return success_counter;
}

int process_c(token* _format) {
  if (_format->length == 'l' && _format->width_const == -1) {
    *((wchar_t*)_format->arg) = _format->str_to_assign[0];
  } else if (_format->width_const != -1) {
    process_s(_format);
  } else {
    *((char*)_format->arg) = _format->str_to_assign[0];
  }
  return 1;
}

int process_di(token* _format) {
  long long int number = 0;
  int status = process_number(_format, &number);
  if (status == 1) {
    if (_format->length == 'h') {
      *((short int*)_format->arg) = number;
    } else if (_format->length == 'l') {
      *((long int*)_format->arg) = number;
    } else if (_format->length == 'L') {
      *((long long*)_format->arg) = number;
    } else {
      *((int*)_format->arg) = number;
    }
  }
  return status;
}

int process_number(token* _format, long long int* number) {
  char digits[2][17] = {{"0123456789ABCDEF"}, {"0123456789abcdef"}};
  int sign = 1;
  int index = 0;
  int status = 1;
  int shift = 0;
  int flag = 0;
  int length = (int)s21_strlen(_format->str_to_assign);
  int notation = get_notation(_format, &shift);
  if (_format->str_to_assign[0] == '-') {
    sign = -1;
    index++;
  } else if (_format->str_to_assign[0] == '+') {
    index++;
  }
  index += shift;
  for (; index < length; ++index) {
    if (_format->str_to_assign[index] == 'x' ||
        _format->str_to_assign[index] == 'X') {
      break;
    }
    int position = 0;
    int compare_status = 1;
    char* compar_ptr = s21_NULL;
    compar_ptr = s21_strchr(digits[0], _format->str_to_assign[index]);
    if (compar_ptr == s21_NULL) {
      compar_ptr = s21_strchr(digits[1], _format->str_to_assign[index]);
      compare_status = 0;
    }
    if (compare_status) {
      position = compar_ptr - digits[0];
    } else {
      position = compar_ptr - digits[1];
    }
    if (position < notation) {
      *number = notation * (*number) + position;
      flag = 1;
    } else {
      break;
    }
  }
  *number *= sign;
  if (flag == 0) {
    status = 0;
    if ((length == 2 || length == 3) && notation == 16) {
      status = 1;
    }
  }
  return status;
}

int get_notation(token* _format, int* shift) {
  int notation = 10;
  int index = 0;
  if (_format->str_to_assign[index] == '+' ||
      _format->str_to_assign[index] == '-') {
    index++;
  }
  if (_format->spec == 'o' || (_format->str_to_assign[index] == '0' &&
                               _format->str_to_assign[index + 1] != 'x')) {
    notation = 8;
  }
  if (_format->spec == 'x' || _format->spec == 'X' || _format->spec == 'p') {
    notation = 16;
  }
  if (_format->str_to_assign[index] == '0' &&
      (_format->str_to_assign[index + 1] == 'x' ||
       _format->str_to_assign[index + 1] == 'X')) {
    notation = 16;
    *shift = 2;
  }
  return notation;
}

int process_ouxX(token* _format) {
  long long int number = 0;
  int status = process_number(_format, &number);
  if (status == 1) {
    if (_format->length == 'h') {
      *((unsigned short int*)_format->arg) = number;
    } else if (_format->length == 'l') {
      *((unsigned long int*)_format->arg) = number;
    } else if (_format->length == 'L') {
      *((unsigned long long*)_format->arg) = number;
    } else {
      *((unsigned int*)_format->arg) = number;
    }
  }
  return status;
}

int process_p(token* _format) {
  long long int number = 0;
  process_number(_format, &number);
  *((int*)_format->arg) = (int)number;
  return 1;
}

int process_s(token* _format) {
  if (_format->length == 0) {
    s21_strcpy(_format->arg, _format->str_to_assign);
  } else if (_format->length == 'l') {
    int length = (int)s21_strlen(_format->str_to_assign);
    wchar_t* str_p = (wchar_t*)_format->arg;
    for (int i = 0; i < length; i++) {
      *str_p = _format->str_to_assign[i];
      str_p++;
    }
    *str_p = '\0';
  }
  return 1;
}

int process_n(token* _format) {
  *((int*)_format->arg) = (int)_format->count_symb;
  return 1;
}

int process_efgEG(token* _format) {
  long double number = 0.0;
  int status = process_double(_format, &number);
  if (status == 1) {
    if (_format->length == 'L') {
      *((long double*)_format->arg) = number;
    } else if (_format->length == 'l') {
      *((double*)_format->arg) = number;
    } else {
      *((float*)_format->arg) = (float)number;
    }
  }
  return status;
}

int process_double(token* _format, long double* number) {
  int sign = 1;
  int str_index = 0;
  int status = 1;
  int index_point = -1;
  int flag = 0;
  char digits[11] = "0123456789";
  int lenght = (int)s21_strlen(_format->str_to_assign);
  if (_format->str_to_assign[0] == '-') {
    sign = -1;
    str_index++;
  } else if (_format->str_to_assign[0] == '+') {
    str_index++;
  }
  for (; str_index < lenght; ++str_index) {
    if (_format->str_to_assign[str_index] == '.') {
      index_point = str_index;
      str_index++;
    }
    if (s21_strchr(digits, _format->str_to_assign[str_index])) {
      int position = 0;
      position = s21_strchr(digits, _format->str_to_assign[str_index]) - digits;
      if (position < 10) {
        *number = 10 * (*number) + position;
        flag = 1;
      }
    } else {
      break;
    }
  }
  *number = (*number) * process_dot_e(_format, index_point, lenght);
  if (flag == 0 || lenght == 0) {
    if (process_inan(_format, sign)) {
      *number = process_inan(_format, sign);
    } else {
      status = 0;
    }
  }
  *number *= sign;
  return status;
}

long double process_dot_e(token* _format, int index_point, int lenght) {
  long double multiplier = 1.0;
  int e_sign = 1;
  int power = 0;
  int e_index = check_e(_format, &e_sign, &power);
  if (index_point != -1 && e_index) {
    multiplier *=
        (1 / pow(10, e_index - index_point - 1)) * pow(10, power * e_sign);
  }
  if (index_point != -1 && !e_index) {
    multiplier /= pow(10, lenght - index_point - 1);
  }
  if (index_point == -1 && e_index) {
    multiplier *= pow(10, power * e_sign);
  }

  return multiplier;
}

int check_e(token* _format, int* e_sign, int* power) {
  int e_index = 0;
  char digits[11] = "0123456789";
  if (s21_strchr(_format->str_to_assign, 'e')) {
    e_index = s21_strchr(_format->str_to_assign, 'e') - _format->str_to_assign;
  }
  if (s21_strchr(_format->str_to_assign, 'E')) {
    e_index = s21_strchr(_format->str_to_assign, 'E') - _format->str_to_assign;
  }
  int lenght = (int)s21_strlen(_format->str_to_assign);
  for (int i = e_index + 1; i < lenght; ++i) {
    int position = 0;
    if (_format->str_to_assign[i] == '-') {
      *e_sign = -1;
      i++;
    }
    position = s21_strchr(digits, _format->str_to_assign[i]) - digits;
    if (position < 10) {
      *power = 10 * (*power) + position;
    } else {
      break;
    }
  }
  return e_index;
}

long double process_inan(token* _format, int sign) {
  long double number = 0;
  if (s21_strstr(_format->str_to_assign, "inf")) {
    number = INFINITY;
  } else if (s21_strstr(_format->str_to_assign, "nan")) {
    if (sign == 1) {
      number = NAN;
    } else {
      number = -NAN;
    }
  }
  return number;
}

int check_char(token* _format, const char* str, int str_index, char format_char,
               int* flag) {
  if (isspace(format_char) != 0) {
    _format->spaces = 1;
  } else {
    while (isspace(str[str_index]) != 0) {
      str_index++;
      _format->count_symb++;
    }
    if (str[str_index] == format_char) {
      str_index++;
      _format->count_symb++;
    } else {
      *flag = 1;
    }
  }
  return str_index;
}
