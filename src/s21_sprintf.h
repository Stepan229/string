#ifndef _SRC_S21_SPRINTF_H_
#define _SRC_S21_SPRINTF_H_

#include "s21_string.h"

typedef struct {
  int plus;
  int minus;
  int hash;
  int space;
  int accuracy;
  int width;
  int zero;
  int number_system;
  int flag_to_size;
  int upper_case;
  int dot;
  int e;
  int g;
  char length;
} Spec;

/**
 * извлекает спецификации формата из строки формата.
 * @param format Строка формата, из которой извлекаются спецификации
 * @param specs Структура, в которую сохраняются спецификации формата.
 * @return Указатель на следующий символ в строке формата после последнего
 * спецификатора
 */
const char *get_specs(const char *format, Spec *specs);

/**
 * извлекает спецификацию precision из строки формата.
 * @param format Строка формата, из которой извлекается спецификацияprecision
 * @param precision Целочисленная переменная, в которую сохраняется спецификация
 * precision.
 * @return Указатель на следующий символ в строке формата после последнего
 * спецификато раprecision
 */
const char *get_width(const char *format, int *width, va_list *arguments);

/**
 * модифицирует структуру Spec, устанавливая различные параметры, такие как
 * ширина поля, точность и т.д.
 * @param specs указатель на структуру Spec
 * @param format указатель на строку формата
 * @param arguments указатель на структуру список аргументов
 * @return возвращает указатель на следующую позицию в строке формата
 */
const char *set_specs(Spec *specs, const char *format, va_list *arguments);

/**
 * Она добавляет символ в указанную строку, увеличивает значение переменной i на
 * единицу
 * @param str указатель на строку
 * @param i указатель на переменную типа int
 * @param symbol символ, который нужно добавить в строку
 * @return возвращает 1.
 */
int add_sym_to_str(char *str, int *i, char symbol);

/**
 * проверяет, нужно ли добавить пробел, знак плюс или минус к числу.
 * Если число положительное и больше 0, то добавляется знак плюс.
 * Если число отрицательное и меньше 0, то добавляется знак минус.
 * Если число положительное или отрицательное и не является первым числом в
 * строке, то добавляется пробел. Функция также обновляет переменные i,
 * flag_to_size и size, чтобы отразить изменения
 * @param specs указатель на структуру Spec
 * @param num длинное число типа long double
 * @param i указатель на переменную типа int
 * @param str_to_num указатель на строку
 * @param flag_to_size указатель на переменную типа int, которая отслеживает
 * размер последней числа в строке
 * @param size отслеживает общее количество чисел, которые нужно распечатать
 * @return функция возвращает значение size_this, которое представляет собой
 * количество чисел, которые еще нужно распечатать
 */
long add_space_plus_minus(Spec specs, long double num, int *i, char *str_to_num,
                          int *flag_to_size, long int *size);

/**
 * Функция проходит по всем символам в буфере, начиная с последнего,
 * и добавляет их в строку, вызывая функцию add_sym_to_str().
 * После каждого добавленного символа увеличивается значение переменной count.
 * Если ширина поля не достигнута, функция добавляет пробел в строку и
 * увеличивает значение переменной count
 * @param width ширина поля
 * @param i указатель на переменную типа int
 * @param buffer указатель на буфер
 * @param str указатель на строку
 * @return возврвозвращает значение count,
 * которое представляет собой количество символов, которые были добавлены в
 * строку.
 */
int add_buffer_to_string(int width, int *i, char *buffer, char *str);

/**
 * проверяет, являются ли оба числа отрицательными, и если да,
 * то изменяет их знаки на положительные
 * @param num_int число инт
 * @param num_double число не инт
 * @return функция возвращает значение флага,
 * которое представляет собой количество чисел, которые были изменены.
 */
int invert_num(long int *num_int, long double *num_double);

/**
 * Она устанавливает номер системы чисел в структуре Spec на основе указанного
 * формата
 * @param specs структура
 * @param format формат
 * @return В конце функция возвращает структуру Spec.
 */
Spec set_number_system(Spec specs, char format);

/**
 * Она возвращает символ, соответствующий числу в указанной системе счисления
 * @param num ы
 * @param upper_case флаг, указывающий, использовать ли верхний регистр
 * @return функция возвращает символ, соответствующий числу.
 */
char get_num_char(int num, int upper_case);

/**
 * а устанавливает соответствующие флаги в структуре Spec
 * для использования десятичной системы счисления и точности.
 * @param specs структура Spec
 * @param format Указатель на текущий символ в строке формата
 * @return функция возвращает структуру Spec.
 */
Spec set_num_sys_double(Spec specs, char format);

/**
 * добавляет ноль к указанной строке, если указанная спецификация
 * содержит требование добавления нулей и флаг установлен в значение,
 * отличное от нуля
 * @param specs структура Spec
 * @param str_to_num номер строки
 * @param size размер
 * @param i указатель на переменную типа int
 * @param flag флаг
 * @return функция возвращает значение размера строки.
 */
int add_zero_to_str(Spec specs, char *str_to_num, s21_size_t size, int *i,
                    int flag);

/**
 * обрабатывает строку формата и список аргументов и генерирует строку,
 * соответствующую спецификациям формата.
 * @param str Строка, к которой добавляется сгенерированная строка
 * @param src Указатель на начало строки формата.
 * @param format Указатель на текущий символ в строке формата.
 * @param specs Структура, содержащая спецификации формата.
 * @param arguments Список аргументов.
 * @return Количество символов, добавленных к строке
 */
char *parser(char *str, char *src, const char *format, Spec specs,
             va_list *arguments);

/**
 * Функция сначала проверяет, какой тип числа нужно распечатать: короткое целое
 * число, длинное целое число или обычное целое число. Затем она вызывает
 * функцию get_size_to_decimal(), чтобы определить размер буфера, необходимого
 * для представления числа в виде строки
 * @param specs Структура, содержащая спецификации формата.
 * @param arguments Список аргументов.
 * @return функция освобождает буфер и возвращает указатель на последнюю позицию
 * в строке
 */
char *print_decimal(char *str, Spec specs, va_list *arguments);

/**
 * Она возвращает размер строки, необходимой для представления числа
 * в виде десятичной строки с использованием указанной ширины поля и точности
 * @param specs Структура, содержащая спецификации формата.
 * @param num цифра ёмаё
 * @return функция возвращает размер строки
 */
s21_size_t get_size_to_decimal(Spec *specs, long int num);

/**
 * преобразует десятичное число в строку, используя указанную ширину поля,
 * точность и требование добавления нулей
 * @param specs Структура, содержащая спецификации формата
 * @param num длинное целое число.
 * @param str_to_num указатель на строку.
 * @param size_to_decimal указатель на переменную типа int
 * @return возвращает значение индекса, на котором она
 * остановилась при добавлении символов к строке
 */
int decimal_to_string(Spec specs, long int num, char *str_to_num,
                      s21_size_t size_to_decimal);

/**
 * выводит аргумент списка в указанную строку,
 * используя указанную ширину поля и точность
 * @param str указатель на строку
 * @param specs Структура, содержащая спецификации формата.
 * @param format символ формата.
 * @param arguments аргумент списка
 * @return функция возвращает указатель на строку
 */
char *print_u(char *str, Spec specs, char format, va_list *arguments);

/**
 * вычисляет размер буфера, необходимого для представления
 * числа в указанной системе счисления
 * @param specs Структура, содержащая спецификации формата.
 * @param num длинное целое число.
 * @return функция возвращает значение размера буфера
 */
s21_size_t get_buf_size_unsigned_decimal(Spec specs, unsigned long int num);

/**
 * преобразует длинное целое число в строку,
 * используя указанную систему счисления, ширину поля и точность.
 * @param buffer указатель на буфер
 * @param specs Структура, содержащая спецификации формата.
 * @param num длинное целое число.
 * @param size_to_num аргумент списка
 * @return возвращает значение индекса, на котором она остановилась
 * при добавлении символов к буферу
 */
int unsigned_decimal_to_string(char *buffer, Spec specs, unsigned long int num,
                               s21_size_t size_to_num);

/**
 * Она выводит целое число в указанную строку,
 * используя указанную ширину поля и точность.
 * @param str указатель на строку
 * @param specs Структура, содержащая спецификации формата.
 * @param symbol символ.
 * @return возвращает возвращает указатель на строку
 */
char *print_c(char *str, Spec specs, int symbol);

/**
 *  выводит строку из списка аргументов в указанную строку,
 * используя указанную ширину поля и точность.
 * @param str указатель на строку
 * @param specs Структура, содержащая спецификации формата.
 * @param symbol список аргументов.
 * @return возвращает возвращает указатель на строку
 */
char *print_s(char *str, Spec specs, va_list *arguments);

/**
 *  выводит строку из списка аргументов в указанную строку,
 * используя указанную ширину поля и точность.
 * @param str указатель на строку
 * @param specs Структура, содержащая спецификации формата.
 * @param arguments список аргументов.
 * @return В конце функция возвращает указатель на строку
 */
char *print_p(char *str, Spec *specs, va_list *arguments);

/**
 * добавляет символы числа с плавающей точкой к указанной строке до тех пор,
 * пока не будет достигнута заданная ширина.
 * @param str указатель на строку
 * @param specs Структура, содержащая спецификации формата.
 * @param format символ формата.
 * @param arguments список аргументов..
 * @return возвращает возвращает указатель на строку
 */
char *print_double(char *str, Spec specs, char format, va_list *arguments);

/**
 * начинает с проверки, является ли точность больше,
 * чем точность в структуре Spec, и если это так,
 * то она продолжает добавлять символы из числа с плавающей точкой
 * в указанную строку до тех пор, пока точность не станет равной точности
 * в структуре Spec.
 * @param str_to_double указатель на строку
 * @param specs Структура, содержащая спецификации формата.
 * @param accuracy целое число точности.
 * @param flag_to_dot флаг, указывающий, следует ли добавить точку.
 * @param size_to_double указатель на переменную размера.
 * @param i указатель на переменную.
 * @param frac дробная часть числа,.
 * @param integer целая часть числа.
 * @return В конце функция возвращает количество символов,
 * использованных для представления числа с плавающей точкой в указанной строке
 */
int add_sym_from_double_to_str(char *str_to_double, Spec specs, int accuracy,
                               int flag_to_dot, s21_size_t size_to_double,
                               int *i, long double frac, long double integer);

/**
 * Она вычисляет размер буфера, необходимый для представления числа
 * в указанной точности.
 * @param num указатель на строку
 * @param specs Структура, содержащая спецификации формата.
 * @return В конце функция возвращает переменную size.
 */
s21_size_t get_size_to_double(Spec *specs, long double num);

/**
 * Она проверяет, является ли число недействительным или бесконечностью,
 * и если это так, то она копирует соответствующую строку в указанную строку.
 * @param specs Структура, содержащая спецификации формата.
 * @param num указатель на строку
 * @param str указатель на строку
 * @return В конце функция возвращает значение флага.
 */
s21_size_t is_nan_or_inf(char *str, long double num, Spec specs);

/**
 * добавляет нули к указанной строке до тех пор,
 * пока не будет достигнута заданная ширина
 * @param str_to_double указатель на строку
 * @param specs Структура, содержащая спецификации формата.
 * @param num целое число точности.
 * @param size_to_double указатель на переменную размера.
 * @param e указатель на переменную.
 * @return В конце функция возвращает ненулевой код ошибки,
 * если число недействительное или бесконечность, или 0 в противном случае
 */
int double_to_string(char *str_to_double, Spec specs, long double num,
                     s21_size_t size_to_double, int e);

/**
 * вычитает количество символов, использованных для представления знака E или e,
 * из переменной размера и добавляет символ E или e к указанной строке.
 * @param e целое число.
 * @param size_to_double размер даблы
 * @param str_to_double указатель на строку
 * @param specs Структура, содержащая спецификации формата.
 * @param i пар-р
 * @return В конце функция возвращает 0.
 */
int print_e(int e, s21_size_t *size_to_double, char *str_to_double, Spec specs,
            int *i);

/**
 * Она нормализует число, устанавливая его значимые цифры
 * и вычисляя необходимое количество значащих цифр.
 * @param num указатель на строку
 * @param specs Структура, содержащая спецификации формата.
 * @return В конце функция возвращает счетчик i,
 * который представляет количество значащих цифр числа.
 */
long double normalize(long double *num, Spec *specs);

/**
 * Она устанавливает соответствующие флаги в структуре Spec
 * для использования десятичной системы счисления и точности,
 * а затем нормализует число, чтобы определить, нужно ли уменьшить точность.
 * @param specs Структура, содержащая спецификации формата.
 * @param num указатель на строку
 * @return В конце функция возвращает копированную структуру Spec.
 */
Spec cutter(Spec specs, long double num);

/**
 * она добавляет 1 к точности, если точность равна 0,
 * и продолжает вычитать количество цифр в целой части числа
 * из точности, пока точность не станет равной 0..
 * @param specs Структура, содержащая спецификации формата.
 * @param num указатель на строку
 * @return В конце функция возвращает количество символов,
 * необходимых для представления числа с плавающей точкой в указанной точности.
 */
s21_size_t get_size_to_e_g(Spec *specs, long double num);

/**
 * она добавляет символы числа с плавающей точкой к указанной строке до тех пор,
 * пока не будет достигнут заданный размер ширины
 * @param str указатель на строку
 * @param specs Структура, содержащая спецификации формата.
 * @param num указатель на строку
 * @return В конце функция возвращает указатель на строку.
 */
char *print_e_g(char *str, Spec specs, char format, va_list *arguments);

#endif  // SRC_S21_SPRINTF_H_