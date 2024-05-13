START_TEST(trim_1) {
  char str[] = "_Evolution_";
  char str_trim[] = "_<,";
  char *exp = "Evolution";
  char *s21_str = (char *)s21_trim(str, str_trim);
  ck_assert_str_eq(s21_str, exp);
  if (s21_str) free(s21_str);
}
END_TEST

START_TEST(trim_2) {
  char str[] = "RaisOfEvolution";
  char str_trim[] = "OfE";
  char *exp = "RaisOfEvolution";
  char *s21_str = (char *)s21_trim(str, str_trim);
  ck_assert_str_eq(s21_str, exp);
  if (s21_str) free(s21_str);
}
END_TEST

START_TEST(trim_3) {
  char str[] = "      Evolution!      ";
  char str_trim[] = " ";
  char *exp = "Evolution!";
  char *s21_str = (char *)s21_trim(str, str_trim);
  ck_assert_str_eq(s21_str, exp);
  if (s21_str) free(s21_str);
}
END_TEST

START_TEST(trim_4) {
  char str[] = "      Evolution!      ";
  char str_trim[] = "";
  char *exp = "Evolution!";
  char *s21_str = (char *)s21_trim(str, str_trim);
  ck_assert_str_eq(s21_str, exp);
  if (s21_str) free(s21_str);
}
END_TEST

START_TEST(trim_5) {
  char str[] = "& -- ?Evolution!&&&---  ?";
  char str_trim[] = "&- ?";
  char *exp = "Evolution!";
  char *s21_str = (char *)s21_trim(str, str_trim);
  ck_assert_str_eq(s21_str, exp);
  if (s21_str) free(s21_str);
}
END_TEST

START_TEST(trim_6) {
  char str[] = "";
  char str_trim[] = ",*&";
  char *exp = "";
  char *s21_str = (char *)s21_trim(str, str_trim);
  ck_assert_str_eq(s21_str, exp);
  if (s21_str) free(s21_str);
}
END_TEST

START_TEST(s21_trim_test) {
  char *str = (char *)s21_trim("|/*1Hello111111/////*****", "/1*|");
  ck_assert_str_eq(str, "Hello");
  free(str);
  str = (char *)s21_trim("|/*1Hello111111/////*****", "");
  ck_assert_str_eq(str, "|/*1Hello111111/////*****");
  free(str);
  str = (char *)s21_trim("", "/1*|");
  ck_assert_str_eq(str, "");
  free(str);
  str = (char *)s21_trim("|/*1111111/////*****", "/1*|");
  ck_assert_str_eq(str, "");
  free(str);
  str = (char *)s21_trim(s21_NULL, s21_NULL);
  ck_assert_ptr_eq(str, s21_NULL);
}
END_TEST