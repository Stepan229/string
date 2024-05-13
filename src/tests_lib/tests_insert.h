START_TEST(insert_1) {
  s21_size_t n = 2;
  char src[128] = "Detion";
  char str[128] = "ad end of evolu";
  char *str_exp = "Dead end of evolution";
  char *str_got = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(str_got, str_exp);
  if (str_got) free(str_got);
}
END_TEST

START_TEST(insert_2) {
  s21_size_t n = 8;
  char src[128] = "Detion";
  char str[128] = "ad end of evolu";
  char *str_exp = s21_NULL;
  char *str_got = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(str_got, str_exp);
  if (str_got) free(str_got);
}
END_TEST

START_TEST(insert_3) {
  s21_size_t n = 8;
  char *src = s21_NULL;
  char str[128] = "ad end of evolu";
  char *str_exp = s21_NULL;
  char *str_got = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(str_got, str_exp);
  if (str_got) free(str_got);
}
END_TEST

START_TEST(insert_4) {
  s21_size_t n = 8;
  char *src = s21_NULL;
  char *str = s21_NULL;
  char *str_exp = s21_NULL;
  char *str_got = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(str_got, str_exp);
  if (str_got) free(str_got);
}
END_TEST

START_TEST(insert_5) {
  s21_size_t n = 8;
  char *src = "";
  char *str = "";
  char *str_exp = s21_NULL;
  char *str_got = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(str_got, str_exp);
  if (str_got) free(str_got);
}
END_TEST

START_TEST(insert_6) {
  s21_size_t n = 8;
  char *src = "";
  char *str = "";
  char *str_exp = s21_NULL;
  char *str_got = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(str_got, str_exp);
  if (str_got) free(str_got);
}
END_TEST