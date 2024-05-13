START_TEST(to_lower_1) {
  char str_1[] = "RAISE OF EVOLUTION!";
  char *str_s21 = (char *)s21_to_lower(str_1);
  char *exp = "raise of evolution!";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST

START_TEST(to_lower_2) {
  char str_1[] = "rAiSe OF evoLuTion! 98127634";
  char *str_s21 = (char *)s21_to_lower(str_1);
  char *exp = "raise of evolution! 98127634";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST

START_TEST(to_lower_3) {
  char str_1[] = ",.?!-_7891355";
  char *str_s21 = (char *)s21_to_lower(str_1);
  char *exp = ",.?!-_7891355";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST

START_TEST(to_lower_4) {
  char str_1[] = "";
  char *str_s21 = (char *)s21_to_lower(str_1);
  char *exp = "";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST