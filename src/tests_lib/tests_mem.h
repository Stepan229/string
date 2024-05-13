START_TEST(memchr_1) {
  s21_size_t num_of_byte = 0;
  char *str_1 = "";
  int search = '\0';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memchr_2) {
  s21_size_t num_of_byte = 9;
  char *str_1 = "Dead end";
  int search = '\0';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memchr_3) {
  s21_size_t num_of_byte = 9;
  char *str_1 = "Dead end";
  int search = '\0';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memchr_4) {
  s21_size_t num_of_byte = 9;
  char *str_1 = "TupiCHok";
  int search = 'T';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memchr_5) {
  s21_size_t num_of_byte = 8;
  char *str_1 = "TupiCHok";
  int search = 'k';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memchr_6) {
  s21_size_t num_of_byte = 14;
  char *str_1 = "Tupi124152CHok";
  int search = '5';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memchr_7) {
  int arr[] = {1, 2, 3, 574, 9, 34};
  s21_size_t num_of_byte = sizeof(int) * 6;
  int search = 574;
  ck_assert_ptr_eq(s21_memchr(arr, search, num_of_byte),
                   memchr(arr, search, num_of_byte));
}
END_TEST

START_TEST(memchr_8) {
  s21_size_t num_of_byte = 9;
  char *str_1 = "TupiCHok";
  int search = 'Z';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memcmp_1) {
  s21_size_t n = 4;
  char *str_1 = "End of evolution";
  char *str_2 = "End of evolution";
  int func = s21_memcmp(str_1, str_2, n);
  int orig = memcmp(str_1, str_2, n);
  ck_assert_int_eq((func == 0), (orig == 0));
}
END_TEST

START_TEST(memcmp_2) {
  s21_size_t n = 9;
  char *str_1 = "End of evolution";
  char *str_2 = "Raise of evolution";
  int func = s21_memcmp(str_1, str_2, n);
  int orig = memcmp(str_1, str_2, n);
  ck_assert_int_eq((func > 0), (orig > 0));
}
END_TEST

START_TEST(memcmp_3) {
  s21_size_t n = 3;
  char *str_1 = "End of evolution";
  char *str_2 = " End of evolution";
  int func = s21_memcmp(str_1, str_2, n);
  int orig = memcmp(str_1, str_2, n);
  ck_assert_int_eq((func > 0), (orig > 0));
}
END_TEST

START_TEST(memcpy_1) {
  s21_size_t bytes_q = 8;
  char str[128] = "";
  char s21_str[128] = "";
  char *src = "11123332\02345";
  ck_assert_pstr_eq(memcpy(str, src, bytes_q),
                    s21_memcpy(s21_str, src, bytes_q));
}
END_TEST

START_TEST(memcpy_2) {
  s21_size_t bytes_q = 8;
  char str[128] = "Evolution team";
  char s21_str[128] = "Evolution team";
  char *src = "reneesaa";
  ck_assert_pstr_eq(memcpy(str, src, bytes_q),
                    s21_memcpy(s21_str, src, bytes_q));
}
END_TEST

START_TEST(memcpy_3) {
  s21_size_t bytes_q = 7;
  char str[128] = "Raise Of Evolution";
  char s21_str[128] = "Raise Of Evolution";
  ck_assert_pstr_eq(memcpy(str, str + 5, bytes_q),
                    s21_memcpy(s21_str, s21_str + 5, bytes_q));
}
END_TEST

START_TEST(memcpy_4) {
  s21_size_t bytes_q = 7;
  char str[128] = "Raise Of Evolution";
  char s21_str[128] = "Raise Of Evolution";
  ck_assert_pstr_eq(memcpy(str, str + 7, bytes_q),
                    s21_memcpy(s21_str, s21_str + 7, bytes_q));
}
END_TEST

START_TEST(memset_1) {
  s21_size_t n = 6;
  int c = '7';
  char str[128] = "Tupichok No More ";
  char s21_str[128] = "Tupichok No More ";
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(s21_str, c, n));
}
END_TEST

START_TEST(memset_2) {
  s21_size_t n = 4;
  int c = '4';
  char str[128] = "Evolution!";
  char s21_str[128] = "Evolution!";
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(s21_str, c, n));
}
END_TEST

START_TEST(memset_3) {
  s21_size_t n = 0;
  int c = '4';
  char str[128] = "Evolution!";
  char s21_str[128] = "Evolution!";
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(s21_str, c, n));
}
END_TEST

START_TEST(memset_4) {
  s21_size_t n = 3;
  int c = '\0';
  char str[128] = "Evolution!";
  char s21_str[128] = "Evolution!";
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(s21_str, c, n));
}
END_TEST

START_TEST(memset_5) {
  s21_size_t n = 3;
  int c = '4';
  char str[128] = "";
  char s21_str[128] = "";
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(s21_str, c, n));
}
END_TEST