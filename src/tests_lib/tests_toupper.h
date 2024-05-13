START_TEST(to_upper_1) {
  char str_1[] = "best team!";
  char *str_s21 = (char *)s21_to_upper(str_1);
  char *exp = "BEST TEAM!";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST

START_TEST(to_upper_2) {
  char str_1[] = "bEsT tEAm!9821";
  char *str_s21 = (char *)s21_to_upper(str_1);
  char *exp = "BEST TEAM!9821";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST

START_TEST(to_upper_3) {
  char str_1[] = "";
  char *str_s21 = (char *)s21_to_upper(str_1);
  char *exp = "";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST

START_TEST(to_upper_4) {
  char str_1[] = ",.?!-_7891355";
  char *str_s21 = (char *)s21_to_upper(str_1);
  char *exp = ",.?!-_7891355";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST