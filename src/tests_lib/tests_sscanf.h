#ifndef BUFF
#define BUFF_SIZE 2048
#endif

START_TEST(sscanf_EOF1) {
  char fstr[] = "%d";
  char str[] = "        ";
  int n_1 = 0, n_2 = 100;
  int32_t res1 = s21_sscanf(str, fstr, n_1);
  int32_t res2 = sscanf(str, fstr, n_2);
  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_EOF2) {
  char fstr[] = "%d ";
  char str[] = "               ";
  int32_t a1 = 0, a2 = 0;

  int32_t res1 = s21_sscanf(str, fstr, &a1);
  int32_t res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_EOF3) {
  char fstr[] = "%d ";
  char str[] = "  ";
  int32_t a1 = 0, a2 = 0;

  int32_t res1 = s21_sscanf(str, fstr, &a1);
  int32_t res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_only_chars1) {
  char fstr[] = "%c %c %c %c";
  char str[] = "   a     b c d";
  int32_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_only_chars2) {
  char fstr[] = "%c%c%c%c";
  char str[] = "abcd";
  int32_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_only_chars3) {
  char fstr[] = "%c %c %c      %c";
  char str[] = "1 a 3   c           ";
  int32_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_only_chars4) {
  char fstr[] = "%c %c %c %c";
  char str[] = "   000 0    ";
  int32_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_only_chars5) {
  char fstr[] = "%c %c %c %c";
  char str[] = "tttt";
  int32_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_special_symbols_as_chars1) {
  char fstr[] = "%c%c%c%c";
  char str[] = "\\\n\t\t\t";
  int32_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_special_symbols_as_chars2) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z ' ' /";
  int32_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_special_symbols_as_chars3) {
  char fstr[] = "%c %*c %c %c";
  char str[] = "A B C D";
  int32_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);

  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}

END_TEST

START_TEST(sscanf_chars_flags1) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int32_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_chars_flags2) {
  char fstr[] = "%1c %c %c %0c";
  char str[] = "z *'@";
  int32_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_chars_flags3) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int32_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_chars_aster1) {
  char fstr[] = "%*c%*c%*c%*c";
  char str[] = "   c ";
  int32_t a1 = 0, a2 = 0;

  int32_t res1 = s21_sscanf(str, fstr, &a1);
  int32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_chars_aster2) {
  char fstr[] = "%*c %*c %*c %c";
  char str[] = "a b c d ";
  int32_t a1 = 0, a2 = 0;

  int32_t res1 = s21_sscanf(str, fstr, &a1);
  int32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_only_ints1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char fstr[] = "%ld %ld %ld %ld";
  const char str[] = "555 666 777 888";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_only_ints2) {
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 3000";
  const char fstr[] = "%hd %hd %hd %hd";

  int res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_only_ints3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 300004";
  const char fstr[] = "%lld %lld %lld %lld";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_ints_nwidth1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 300004";
  const char fstr[] = "%1lld %3lld %1lld %4lld";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_ints_nwidth2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%1lld %1lld %1lld %1lld";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_ints_nwidth3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "100 000 00 00";
  const char fstr[] = "%lld %lld %lld %lld";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_ints_nwidth4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 12 5 90";
  const char fstr[] = "%15lld %1lld %1lld %1lld";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_ints_astwidth1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  const char str[] = "1337123123 1 123412341234 1 999999 0";
  const char fstr[] = "%*d %lld %*d %lld %*d %lld";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}

END_TEST

START_TEST(sscanf_ints_astwidth2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15lld %1lld %1lld %1lld";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_ints_astwidth3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15lld %1lld %1lld %1lld";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_ints_astwidth4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15lld %1lld %1lld %1lld";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_signed_ints1) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "11337 3 -5 -4";
  const char fstr[] = "%d %d %d %d";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_signed_ints2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +1 1 -1";
  const char fstr[] = "%lld %lld %1lld %lld";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_signed_ints3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-0 +0 +0 -0";
  const char fstr[] = "%2lld %2lld %2lld %2lld";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_signed_ints4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1 01 10 0";
  const char fstr[] = "%lld %lld %lld %lld";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_spec_i_int1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300 500 -600 +700";
  const char fstr[] = "%lli %lli %lli %lli";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_spec_i_int2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300500-600+700 111";
  const char fstr[] = "%lli %lld %lld %lli";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_spec_i_int3) {
  long long a1 = 0, a2 = 0, c1 = 0, c2 = 0;
  char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300500-600+700+400";
  const char fstr[] = "%lli%c%lli%c";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(c1, c2);
}

END_TEST

START_TEST(sscanf_spec_i_int4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "55555";
  const char fstr[] = "%lli %lld %lld %lli";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_spec_i_hex1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "0x2f23 123 50 0x123123";
  const char fstr[] = "%lli %lld %lld %lli";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_spec_i_hex2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "0x2c23 321 17 0x1241253";
  const char fstr[] = "%lli %lld %lld %lli";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_spec_i_oct1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  55555 3 2  0xf ";
  const char fstr[] = "%lli %lld %lld %lli";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_spec_i_oct2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  0552355 3 12  0xc ";
  const char fstr[] = "%lli %lld %lld %lli";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

// [%s] //
START_TEST(sscanf_strings1) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
  const char fstr[] = "%s %s %s %s";

  int32_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int32_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}

END_TEST

START_TEST(sscanf_strings_mixed3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "Aboba 123 Floppa -3 Keppa 4444Shleppa 333Anuroba 3";
  const char fstr[] = "%s%ld%s%d%s%d%s";

  int32_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
  int32_t res2 = s21_sscanf(str, fstr, s5, &a2, s6, &b2, s7, &c2, s8, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}

END_TEST

START_TEST(sscanf_strings2) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%s%s%s%s";

  int32_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int32_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}

END_TEST

START_TEST(sscanf_strings3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tkepaboba floppa shleppa koooppa ap p p p p";
  const char fstr[] = "%*s%*s%*s%*s";

  int32_t res1 = s21_sscanf(str, fstr);
  int32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}

END_TEST

START_TEST(sscanf_strings4) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%1s%1s%1s%1s";

  int32_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int32_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}

END_TEST

START_TEST(sscanf_strings5) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%3s%3s%3s%3s";

  int32_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int32_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}

END_TEST

START_TEST(sscanf_strings6) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%150s%1s%1s\t%3s";

  int32_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int32_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}

END_TEST

// strings_mixed1
START_TEST(sscanf_strings_mixed1) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long long d1 = 0, d2 = 0;
  long double e1 = 0, e2 = 0;

  const char str[] =
      "4444444"
      "eeeeeee\teeeeeee";
  const char fstr[] = "%5s %1s %*s %*s %llu %s %llu %llu %lld %Lf %33s";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};
  char s9[BUFF_SIZE] = {'\0'};
  char s10[BUFF_SIZE] = {'\0'};

  int32_t res1 = s21_sscanf(str, fstr, s7, s9, &a1, s5, &b1, &c1, &d1, &e1, s1);
  int32_t res2 = sscanf(str, fstr, s8, s10, &a2, s6, &b2, &c2, &d2, &e2, s2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_strings_mixed2) {
  int d1 = 0, d2 = 0, b1 = 0, b2 = 0, a1 = 0, a2 = 0;
  long long v1, v2;

  const char str[] = "1 1 1 1 1 -1";
  const char fstr[] = "%1s %5d %1s %1s %d %lld %d";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};

  int32_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, s3, &b1, &v1, &d1);
  int32_t res2 = sscanf(str, fstr, s4, &a2, s5, s6, &b2, &v2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

// [%n] //
START_TEST(sscanf_n1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int32_t n1 = 0, n2 = 5;

  const char str[BUFF_SIZE] = "50 160 70 80";
  const char fstr[BUFF_SIZE] = "%lli %lli %n %lli %lli";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_n2) {
  int n1 = 1, n2 = 5;

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};

  const char str[] = "cbobErobM fl? asdfasdflkasdf asdfasdf asdfasdf 88888";
  const char fstr[] = "%s %s %n %s";

  int32_t res1 = s21_sscanf(str, fstr, s1, s2, &n1, s3);
  int32_t res2 = sscanf(str, fstr, s5, s6, &n2, s7);

  ck_assert_int_eq(res1, res2);

  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
}

END_TEST

START_TEST(sscanf_n3) {
  int n1 = 0, n2 = 5;

  const char str[BUFF_SIZE] = "50 60 70 80";
  const char fstr[BUFF_SIZE] = "%n";

  int32_t res1 = s21_sscanf(str, fstr, &n1);
  int32_t res2 = sscanf(str, fstr, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}

END_TEST

START_TEST(sscanf_n4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int32_t n1 = 0, n2 = 5;

  const char str[] = "50 60 70 80";
  const char fstr[] = "%lli %lli %n %lli %lli";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_n5) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int n1 = 0, n2 = 5;

  const char str[] = "50 60 70 80";
  const char fstr[] = "%lli %lli %n %lli %lli";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

// [%f] / [%g] / %[%G] //
START_TEST(sscanf_floats1) {
  long double a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0, d1 = 1, d2 = 0;

  const char str[] = "53.1 -4.1135 41.3333 +2.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq_tol(a1, a2, 1e-6);
  ck_assert_double_eq_tol(b1, b2, 1e-6);
  ck_assert_double_eq_tol(c1, c2, 1e-6);
  ck_assert_double_eq_tol(d1, d2, 1e-6);
}

END_TEST

START_TEST(sscanf_floats2) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "0.00001 -4123123 4. .";
  const char fstr[] = "%lf %lf %lf %lf";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq_tol(a1, a2, 1e-6);
  ck_assert_double_eq_tol(b1, b2, 1e-6);
  ck_assert_double_eq_tol(c1, c2, 1e-6);
  ck_assert_double_eq_tol(d1, d2, 1e-6);
}

END_TEST

START_TEST(sscanf_floats3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = ". . . .";
  const char fstr[] = "%f %f %f %f";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_floats4) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "513.41 -4.14135 414.3333 +112.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq_tol(a1, a2, 1e-6);
  ck_assert_double_eq_tol(b1, b2, 1e-6);
  ck_assert_double_eq_tol(c1, c2, 1e-6);
  ck_assert_double_eq_tol(d1, d2, 1e-6);
}

END_TEST

START_TEST(sscanf_floats_sci3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "inF InF inF INF";
  const char fstr[] = "%G %G %G %G";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_floats_sci4) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "Nan NAN 0.0000 0";
  const char fstr[] = "%G %G %G %G";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_float_nan(b1);
  ck_assert_float_nan(b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_floats_sci5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] =
      "nAN           -INF                   -0.1111         1e-10";
  const char fstr[] = "%G %G %G %G";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq_tol(c1, c2, 1e-6);
  ck_assert_ldouble_eq_tol(d1, d2, 1e-6);
}

END_TEST

// [%u] //
START_TEST(sscanf_uint1) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_uint_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_uint2) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                         d2 = 0;
  const char str[] = "-1337 233333331 5008 3000";
  const char fstr[] = "%1llu %2llu %5llu %4llu";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_uint3) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long long d1 = 0, d2 = 0;
  long double v1, v2;

  const char str[] =
      "\t\t\t\t\t\n 3      adsfdfa%$$$$`adfasdfasdfaszcvzcxvcv -1337 "
      "anurobich+ 21 -5008 -33000 0.3333";
  const char fstr[] = "%*s %*s %llu %s %llu %llu %lld %Lf";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};

  int32_t res1 = s21_sscanf(str, fstr, &a1, s1, &b1, &c1, &d1, &v1);
  int32_t res2 = sscanf(str, fstr, &a2, s2, &b2, &c2, &d2, &v2);

  ck_assert_uint_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_ldouble_eq_tol(v1, v2, 0.0001);
}

END_TEST

START_TEST(sscanf_uint4) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_uint5) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_uint6) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_upeer_hex_base_version) {
  uint32_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_upeer_hex_overflow) {
  uint32_t a1, a2;
  const char str[] = "0xFFFFFFFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_upeer_hex_0X) {
  uint32_t a1, a2;
  const char str[] = "A";
  const char fstr[] = "%X";
  s21_sscanf(str, fstr, &a1);
  sscanf(str, fstr, &a2);

  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_upeer_hex_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_upeer_hex_fail) {
  uint32_t a1, a2;
  const char str[] = "qF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_upeer_hex_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_upeer_hex_short) {
  uint16_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%hX";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_upeer_hex_long) {
  unsigned long int a1, a2;
  const char str[] = "F";
  const char fstr[] = "%lX";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_upeer_hex_longlong) {
  unsigned long long int a1, a2;
  const char str[] = "F";
  const char fstr[] = "%llX";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_upeer_hex_2x) {
  uint32_t a1, a2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_upeer_hex_star) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*X";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_upeer_hex_nohex) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_upeer_hex_lower) {
  uint32_t a1, a2;
  const char str[] = "abcdef";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_upeer_hex_sign) {
  uint32_t a1, a2;
  const char str[] = "-f";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_lower_hex_base_version) {
  uint32_t a1, a2;
  const char str[] = "f";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_lower_hex_overflow) {
  uint32_t a1, a2;
  const char str[] = "0xfffffffffffffffffff";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_lower_hex_0x) {
  uint32_t a1, a2;
  const char str[] = "a";
  const char fstr[] = "%x";
  s21_sscanf(str, fstr, &a1);
  sscanf(str, fstr, &a2);

  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_lower_hex_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_lower_hex_fail) {
  uint32_t a1, a2;
  const char str[] = "qF";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_lower_hex_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     F";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_lower_hex_short) {
  uint16_t a1, a2;
  const char str[] = "ff";
  const char fstr[] = "%hx";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_lower_hex_long) {
  unsigned long int a1, a2;
  const char str[] = "ff";
  const char fstr[] = "%lx";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_lower_hex_longlong) {
  unsigned long long int a1, a2;
  const char str[] = "faaaaaaaaaaaaf";
  const char fstr[] = "%llx";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_lower_hex_2x) {
  uint32_t a1, a2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_lower_hex_star) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*x";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_lower_hex_nohex) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_lower_hex_lower) {
  uint32_t a1, a2;
  const char str[] = "abcdef";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_lower_hex_sign) {
  uint32_t a1, a2;
  const char str[] = "-f";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(upper_hex_len) {
  uint32_t a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_lower_hex_len) {
  uint32_t a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_octal_base_version) {
  uint32_t a1, a2;
  const char str[] = "777";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_octal_overflow) {
  uint32_t a1, a2;
  const char str[] = "0x7777777777777777777777";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_octal_0x) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_octal_0X) {
  uint32_t a1, a2;
  const char str[] = "0X";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_octal_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_octal_fail) {
  uint32_t a1, a2;
  const char str[] = "q1";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_octal_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     5";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_octal_short) {
  uint16_t a1, a2;
  const char str[] = "12";
  const char fstr[] = "%ho";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_octal_long) {
  unsigned long int a1, a2;
  const char str[] = "57234";
  const char fstr[] = "%lo";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_octal_longlong) {
  unsigned long long int a1, a2;
  const char str[] = "12356226137";
  const char fstr[] = "%llo";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_octal_2x) {
  uint32_t a1, a2;
  const char str[] = "0x12320x213x123213";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_octal_star) {
  const char str[] = "521561612";
  const char fstr[] = "%*o";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_octal_nohex) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(sscanf_octal_lower) {
  uint32_t a1, a2;
  const char str[] = "01234567";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_octal_sign) {
  uint32_t a1, a2;
  const char str[] = "-66";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_octal_len) {
  uint32_t a1, a2;
  const char str[] = "123531";
  const char fstr[] = "%2o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(sscanf_buff1) {
  int32_t a1, a2;
  int32_t b1, b2;
  const char str[] = "12 keppa 12";
  const char fstr[] = "%d keppa %d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}

END_TEST

START_TEST(sscanf_buff2) {
  int32_t a1, a2;
  int32_t b1, b2;
  const char str[] = "12keppa12";
  const char fstr[] = "%dkeppa%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}

END_TEST

START_TEST(sscanf_pointer1) {
  void *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_mixed_ptrs1) {
  void *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char str[] = "0x4 0x3 0x2 0x1";
  const char fstr[] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}

END_TEST

START_TEST(sscanf_hard1) {
  int a1 = 0, a2 = 5, a3 = 3, a4 = 9;
  int32_t n1 = 500, n2 = 10000;

  const char str[] = "123123SkipMePlease!!!!123";
  const char fstr[] = "%dSkipMePlease!!!!%d %n";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &a3, &n1);
  int32_t res2 = sscanf(str, fstr, &a2, &a4, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a3, a4);
  ck_assert_int_eq(n1, n2);
}

END_TEST

START_TEST(s21_sscanf_space_and_empty_test) {
  char str1[] = "         ";
  char str2[] = "";
  int a = 0;
  char a1 = '\0';
  int b = 0;
  char b1 = '\0';

  ck_assert_int_eq(sscanf(str1, "%d%c", &a, &a1),
                   s21_sscanf(str1, "%d%c", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(sscanf(str2, "%c%d", &a1, &a),
                   s21_sscanf(str2, "%c%d", &b1, &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(s21_sscanf_suppress_test) {
  char str1[] = "qwerty";
  char str2[] = "5 %    3";
  int a = 0;
  int a1 = 0;
  char a2 = '\0';
  int b = 0;
  int b1 = 0;
  char b2 = '\0';

  ck_assert_int_eq(sscanf(str1, "%%%d%d%c", &a, &a1, &a2),
                   s21_sscanf(str1, "%%%d%d%c", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);

  ck_assert_int_eq(sscanf(str1, "%d%d", &a, &a1),
                   s21_sscanf(str1, "%d%d", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);

  ck_assert_int_eq(sscanf(str2, "%c%%%d", &a2, &a),
                   s21_sscanf(str2, "%c%%%d", &b2, &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a2, b2);

  ck_assert_int_eq(sscanf(str2, "%d %% %d", &a, &a1),
                   s21_sscanf(str2, "%d %% %d", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);

  ck_assert_int_eq(sscanf(str1, "%*c%*c%*c%c", &a2),
                   s21_sscanf(str1, "%*c%*c%*c%c", &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);

  ck_assert_int_eq(sscanf(str2, "%d %*c %d", &a, &a1),
                   s21_sscanf(str2, "%d %*c %d", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
}
END_TEST

START_TEST(s21_sscanf_c_normal_spec_test) {
  char str1[] = "ji";
  char str2[] = " t  5";
  char str3[] = "         g          n";

  char a = 0;
  char a1 = 0;
  int a2 = 0;
  char b = 0;
  char b1 = 0;
  int b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%c%c", &a, &a1),
                   s21_sscanf(str1, "%c%c", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  ck_assert_int_eq(sscanf(str2, " %c%c", &a, &a1),
                   s21_sscanf(str2, " %c%c", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  ck_assert_int_eq(sscanf(str2, "%c%d", &a, &a2),
                   s21_sscanf(str2, "%c%d", &b, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a2 = 0;
  b2 = 0;
  ck_assert_int_eq(sscanf(str3, "%c%c", &a, &a1),
                   s21_sscanf(str3, "%c%c", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  ck_assert_int_eq(
      sscanf(str3, "                %c             %c                  ", &a,
             &a1),
      s21_sscanf(str3, "                %c             %c                  ",
                 &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  ck_assert_int_eq(sscanf(str2, "%c    %d", &a, &a2),
                   s21_sscanf(str2, "%c    %d", &b, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(s21_sscanf_d_normal_signs_spec_test) {
  char str1[] = "95 4432 84884";
  char str2[] = "35d 5fg44444";
  char str3[] = "-54 +f +345";
  char str4[] = "  55    -444 g";
  int a = 0;
  int a1 = 0;
  int a2 = 0;
  int b = 0;
  int b1 = 0;
  int b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%d%d%d", &a, &a1, &a2),
                   s21_sscanf(str1, "%d%d%d", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%2d%4d%5d", &a, &a1, &a2),
                   s21_sscanf(str1, "%2d%4d%5d", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%10d %2d", &a, &a1),
                   s21_sscanf(str1, "%10d %2d", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str2, "%d%d %d", &a, &a1, &a2),
                   s21_sscanf(str2, "%d%d %d", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str3, " %d%d ", &a, &a1),
                   s21_sscanf(str3, " %d%d ", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str4, "%d %d", &a, &a1),
                   s21_sscanf(str4, "%d %d", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_d_width_length_spec_test) {
  char str1[] = "954432848 84";
  char str2[] = "32767";
  char str3[] = "4345";
  char str4[] = "2147483647  55";
  long int a = 0;
  short int a1 = 0;
  long int b = 0;
  short int b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%ld%hd", &a, &a1),
                   s21_sscanf(str1, "%ld%hd", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str2, "%hd", &a1), s21_sscanf(str2, "%hd", &b1));
  ck_assert_int_eq(a1, b1);
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%3hd %1ld", &a1, &a),
                   s21_sscanf(str1, "%3hd %1ld", &b1, &b));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str3, "%3hd %1ld", &a1, &a),
                   s21_sscanf(str3, "%3hd %1ld", &b1, &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str4, "%ld", &a), s21_sscanf(str4, "%ld", &b));
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str4, "%8ld %1hd", &a, &a1),
                   s21_sscanf(str4, "%8ld %1hd", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_i_normal_signs_spec_test) {
  char str1[] = "345670";
  char str2[] = "0x2134";
  char str3[] = "1ABE 0x56E";
  char str4[] = "1abd ZXMN 0x56E23";
  char str5[] = "+E6BC -0x844621";
  char str6[] = "+++43FFFF ----0xeabc753";

  int a = 0;
  int a1 = 0;
  int b = 0;
  int b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%i", &a), s21_sscanf(str1, "%i", &b));
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str2, "%i", &a), s21_sscanf(str2, "%i", &b));
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str3, "%i %i", &a, &a1),
                   s21_sscanf(str3, "%i %i", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str4, "%i %i", &a, &a1),
                   s21_sscanf(str4, "%i %i", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str5, "%i %i", &a, &a1),
                   s21_sscanf(str5, "%i %i", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str6, "%i %i", &a, &a1),
                   s21_sscanf(str6, "%i %i", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_i_width_length_spec_test) {
  char str1[] = "567809887";
  char str2[] = "0x456787655";

  int a = 0;
  short int a1 = 0;
  long int a2 = 0;
  int b = 0;
  short int b1 = 0;
  long int b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%8i", &a), s21_sscanf(str1, "%8i", &b));
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;
  ck_assert_int_eq(sscanf(str2, "%8i", &a), s21_sscanf(str2, "%8i", &b));
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str1, "%8hi", &a1), s21_sscanf(str1, "%8hi", &b1));
  ck_assert_int_eq(a1, b1);
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%8li", &a2), s21_sscanf(str1, "%8li", &b2));
  ck_assert_int_eq(a2, b2);
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%1i %1hi %1li", &a, &a1, &a2),
                   s21_sscanf(str1, "%1i %1hi %1li", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;
}
END_TEST

START_TEST(s21_sscanf_f_normal_sign_point_spec_test) {
  char str1[] = "123";
  char str2[] = "ab";
  char str3[] = "a.05";
  char str4[] = "123.ab";
  char str5[] = "0.123 10.04d";
  char str6[] = "+1234.5678 -0.00005";
  char str7[] = "+++5.21 --0.521";

  float a = 0;
  float a1 = 0;
  float b = 0;
  float b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%f", &a), s21_sscanf(str1, "%f", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str2, "%f", &a), s21_sscanf(str2, "%f", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str3, "%f", &a), s21_sscanf(str3, "%f", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str4, "%f", &a), s21_sscanf(str4, "%f", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str5, "%f %f", &a, &a1),
                   s21_sscanf(str5, "%f %f", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str6, "%f %f", &a, &a1),
                   s21_sscanf(str6, "%f %f", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str7, "%f %f", &a, &a1),
                   s21_sscanf(str7, "%f %f", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_f_width_length_spec_test) {
  char str1[] = "123898564498.444984949893";
  char str2[] =
      "+1.1897314953572317650857593266280070162 "
      "-0.5192296858534827628530496329220096";
  char str3[] = " 3.1415926535897932384626433832795029L -2423452";

  long double a = 0;
  double a1 = 0;
  long double b = 0;
  double b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%Lf", &a), s21_sscanf(str1, "%Lf", &b));
  ck_assert_ldouble_eq_tol(a, b, 1e-8);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str2, "%Lf %lf", &a, &a1),
                   s21_sscanf(str2, "%Lf %lf", &b, &b1));
  ck_assert_ldouble_eq_tol(a, b, 1e-10);
  ck_assert_double_eq_tol(a1, b1, 1e-10);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str3, "%Lf %lf", &a, &a1),
                   s21_sscanf(str3, "%Lf %lf", &b, &b1));
  ck_assert_ldouble_eq_tol(a, b, 1e-10);
  ck_assert_double_eq_tol(a1, b1, 1e-10);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%1Lf", &a), s21_sscanf(str1, "%1Lf", &b));
  ck_assert_ldouble_eq_tol(a, b, 1e-10);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str2, "%6Lf %1lf", &a, &a1),
                   s21_sscanf(str2, "%6Lf %1lf", &b, &b1));
  ck_assert_ldouble_eq_tol(a, b, 1e-10);
  ck_assert_double_eq_tol(a1, b1, 1e-10);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str2, "%10Lf %10lf", &a, &a1),
                   s21_sscanf(str2, "%10Lf %10lf", &b, &b1));
  ck_assert_ldouble_eq_tol(a, b, 1e-10);
  ck_assert_double_eq_tol(a1, b1, 1e-10);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_f_multi_dots_inf_nan_spec_test) {
  char str1[] = "4.7.85.1";
  char str2[] = "09..3 2.1";
  char str3[] = "inf nan";
  char str4[] = "+inf -nan";
  char str5[] = "50.12 -inf";
  char str6[] = "+nan 90000000.00000001";
  float a = 0;
  float a1 = 0;
  float b = 0;
  float b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%f", &a), s21_sscanf(str1, "%f", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str2, "%f %f", &a, &a1),
                   s21_sscanf(str2, "%f %f", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str3, "%f %f", &a, &a1),
                   s21_sscanf(str3, "%f %f", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str4, "%f %f", &a, &a1),
                   s21_sscanf(str4, "%f %f", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str5, "%f %f", &a, &a1),
                   s21_sscanf(str5, "%f %f", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str6, "%f %f", &a, &a1),
                   s21_sscanf(str6, "%f %f", &b, &b1));
  ck_assert_float_nan(a);
  ck_assert_float_nan(b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_geGE_normal_sign_point_spec_test) {
  char str1[] = "123";
  char str2[] = "ab";
  char str3[] = "0.123 10.04d";
  char str4[] = "+1234.5678 -0.00005";
  char str5[] = "+++5.21 --0.521";

  float a = 0;
  float a1 = 0;
  float b = 0;
  float b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%g", &a), s21_sscanf(str1, "%g", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str1, "%e", &a), s21_sscanf(str1, "%e", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str2, "%g", &a), s21_sscanf(str2, "%g", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str2, "%e", &a), s21_sscanf(str2, "%e", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str1, "%G", &a), s21_sscanf(str1, "%G", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str1, "%E", &a), s21_sscanf(str1, "%E", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str2, "%G", &a), s21_sscanf(str2, "%G", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str2, "%G", &a), s21_sscanf(str2, "%E", &b));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str3, "%g%e", &a, &a1),
                   s21_sscanf(str3, "%g%e", &b, &b1));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str3, "%G%E", &a, &a1),
                   s21_sscanf(str3, "%G%E", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str4, "%g%e", &a, &a1),
                   s21_sscanf(str4, "%g%e", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str4, "%G%E", &a, &a1),
                   s21_sscanf(str4, "%G%E", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str5, "%g%e", &a, &a1),
                   s21_sscanf(str5, "%g%e", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str5, "%G%E", &a, &a1),
                   s21_sscanf(str5, "%G%E", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_geGE_exp_spec_test) {
  char str1[] = "+110e-3 -10e4";
  char str2[] = "10e-5 -0.e5";
  char str3[] = "12.3e5 32.2E-5";

  float a = 0;
  float a1 = 0;
  float b = 0;
  float b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%g%e", &a, &a1),
                   s21_sscanf(str1, "%g%e", &b, &b1));
  ck_assert_float_eq(a, b);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%G%E", &a, &a1),
                   s21_sscanf(str1, "%G%E", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str2, "%g%e", &a, &a1),
                   s21_sscanf(str2, "%g%e", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str2, "%G%E", &a, &a1),
                   s21_sscanf(str2, "%G%E", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str3, "%g%e", &a, &a1),
                   s21_sscanf(str3, "%g%e", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str3, "%G%E", &a, &a1),
                   s21_sscanf(str3, "%G%E", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_geGE_width_length_spec_test) {
  char str1[] = "+110e-3 -10e4 -696878e-3";
  char str2[] = "109654e-5 -0.1897e5 -39e5";
  char str3[] = "12.3e5 32.2E-5 765.0853656756";

  float a = 0;
  double a1 = 0;
  long double a2 = 0;
  float b = 0;
  double b1 = 0;
  long double b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%lg%3e%9LG", &a1, &a, &a2),
                   s21_sscanf(str1, "%lg%3e%9LG", &b1, &b, &b2));
  ck_assert_float_eq(a, b);
  ck_assert_double_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str2, "%1lE %3LG %5E", &a1, &a2, &a),
                   s21_sscanf(str2, "%1lE %3LG %5E", &b1, &b2, &b));
  ck_assert_float_eq(a, b);
  ck_assert_double_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str3, "%2G %3lG %12Le", &a, &a1, &a2),
                   s21_sscanf(str3, "%2G %3lG %12Le", &b, &b1, &b2));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;
}
END_TEST

START_TEST(s21_sscanf_geGE_multi_dots_inf_nan_spec_test) {
  char str1[] = "4.7.85.1";
  char str2[] = "09..3 2.1";
  char str3[] = "inf nan";
  char str4[] = "+inf -nan";
  char str5[] = "50.12 -inf";
  char str6[] = "+nan 90000000.00000001";
  char str7[] = "1.2e3e-5 5.34e-65e4";
  float a = 0;
  float a1 = 0;
  float b = 0;
  float b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%g%G", &a, &a1),
                   s21_sscanf(str1, "%g%G", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%e%E", &a, &a1),
                   s21_sscanf(str1, "%e%E", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str2, "%g %e", &a, &a1),
                   s21_sscanf(str2, "%g %e", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str2, "%G %E", &a, &a1),
                   s21_sscanf(str2, "%G %E", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str3, "%g %e", &a, &a1),
                   s21_sscanf(str3, "%g %e", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str3, "%G %E", &a, &a1),
                   s21_sscanf(str3, "%G %E", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str4, "%g %e", &a, &a1),
                   s21_sscanf(str4, "%g %e", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str4, "%G %E", &a, &a1),
                   s21_sscanf(str4, "%G %E", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str5, "%g %e", &a, &a1),
                   s21_sscanf(str5, "%g %e", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str5, "%G %E", &a, &a1),
                   s21_sscanf(str5, "%G %E", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str6, "%g %e", &a, &a1),
                   s21_sscanf(str6, "%g %e", &b, &b1));
  ck_assert_float_nan(a);
  ck_assert_float_nan(b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str6, "%G %E", &a, &a1),
                   s21_sscanf(str6, "%G %E", &b, &b1));
  ck_assert_float_nan(a);
  ck_assert_float_nan(b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str7, "%g %e", &a, &a1),
                   s21_sscanf(str7, "%g %e", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str7, "%G %E", &a, &a1),
                   s21_sscanf(str7, "%G %E", &b, &b1));
  ck_assert_float_eq(a, b);
  ck_assert_float_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_o_normal_sign_spec_test) {
  char str1[] = "655 4432 84884";
  char str2[] = "35d 5fg44444";
  char str3[] = "-54 +f +345";
  char str4[] = "  55    -444 g";

  unsigned int a = 0;
  unsigned int a1 = 0;
  unsigned int a2 = 0;
  unsigned int b = 0;
  unsigned int b1 = 0;
  unsigned int b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%o%o%o", &a, &a1, &a2),
                   s21_sscanf(str1, "%o%o%o", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%2o%4o%5o", &a, &a1, &a2),
                   s21_sscanf(str1, "%2o%4o%5o", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%10o %2o", &a, &a1),
                   s21_sscanf(str1, "%10o %2o", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str2, "%o%o %o", &a, &a1, &a2),
                   s21_sscanf(str2, "%o%o %o", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str3, " %o%o ", &a, &a1),
                   s21_sscanf(str3, " %o%o ", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str4, "%o %o", &a, &a1),
                   s21_sscanf(str4, "%o %o", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_o_width_length_spec_test) {
  char str1[] = "z54432848 84";
  char str2[] = "32767";
  char str3[] = "4345";
  char str4[] = "2147483647  55";
  unsigned long int a = 0;
  unsigned short int a1 = 0;
  unsigned long int b = 0;
  unsigned short int b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%lo%ho", &a, &a1),
                   s21_sscanf(str1, "%lo%ho", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str2, "%ho", &a1), s21_sscanf(str2, "%ho", &b1));
  ck_assert_int_eq(a1, b1);
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%3ho %1lo", &a1, &a),
                   s21_sscanf(str1, "%3ho %1lo", &b1, &b));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str3, "%3ho %1lo", &a1, &a),
                   s21_sscanf(str3, "%3ho %1lo", &b1, &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str4, "%lo", &a), s21_sscanf(str4, "%lo", &b));
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str4, "%1lo %8ho", &a, &a1),
                   s21_sscanf(str4, "%1lo %8ho", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_s_normal_spec_test) {
  char str1[] = "reowrow[piefowkefojwreofwef5458we48328]";
  char str2[] = "ddiuh iojoi fowra weaopf olasd";

  char strt_a[100] = {0};
  char strt_a1[100] = {0};
  char strt_b[100] = {0};
  char strt_b1[100] = {0};

  ck_assert_int_eq(sscanf(str1, "%s", strt_a), s21_sscanf(str1, "%s", strt_b));
  ck_assert_str_eq(strt_a, strt_b);
  for (int i = 0; i < 100; ++i) {
    strt_a[i] = 0;
    strt_b[i] = 0;
  }
  ck_assert_int_eq(sscanf(str2, "%s %s", strt_a, strt_a1),
                   s21_sscanf(str2, "%s %s", strt_b, strt_b1));
  ck_assert_str_eq(strt_a, strt_b);
  ck_assert_str_eq(strt_a1, strt_b1);
}
END_TEST

START_TEST(s21_sscanf_s_width_length_spec_test) {
  char str1[] = "herlofsl wqe,d dff";
  char str2[] = "d'sao pdpd spadopopopoopopop";

  wchar_t strtw_a[100] = {0};
  wchar_t strtw_a1[100] = {0};
  wchar_t strtw_b[100] = {0};
  wchar_t strtw_b1[100] = {0};

  char strt_a[100] = {0};
  char strt_a1[100] = {0};
  char strt_b[100] = {0};
  char strt_b1[100] = {0};

  ck_assert_int_eq(sscanf(str1, "%1s", strt_a),
                   s21_sscanf(str1, "%1s", strt_b));
  ck_assert_str_eq(strt_a, strt_b);
  for (int i = 0; i < 100; ++i) {
    strt_a[i] = 0;
    strt_b[i] = 0;
  }

  ck_assert_int_eq(sscanf(str1, "%8s", strt_a),
                   s21_sscanf(str1, "%8s", strt_b));
  ck_assert_str_eq(strt_a, strt_b);
  for (int i = 0; i < 100; ++i) {
    strt_a[i] = 0;
    strt_b[i] = 0;
  }

  ck_assert_int_eq(sscanf(str2, "%9s %2s", strt_a, strt_a1),
                   s21_sscanf(str2, "%9s %2s", strt_b, strt_b1));
  ck_assert_str_eq(strt_a, strt_b);
  ck_assert_str_eq(strt_a1, strt_b1);
  for (int i = 0; i < 100; ++i) {
    strt_a[i] = 0;
    strt_b[i] = 0;
    strt_a1[i] = 0;
    strt_b1[i] = 0;
  }

  ck_assert_int_eq(sscanf(str1, "%ls", strtw_a),
                   s21_sscanf(str1, "%ls", strtw_b));
  ck_assert_mem_eq(strtw_a, strtw_b, 100);
  for (int i = 0; i < 100; ++i) {
    strtw_a[i] = 0;
    strtw_b[i] = 0;
  }

  ck_assert_int_eq(sscanf(str1, "%10ls", strtw_a),
                   s21_sscanf(str1, "%10ls", strtw_b));
  ck_assert_mem_eq(strtw_a, strtw_b, 100);
  for (int i = 0; i < 100; ++i) {
    strtw_a[i] = 0;
    strtw_b[i] = 0;
  }

  ck_assert_int_eq(sscanf(str2, "%9ls %2ls", strtw_a, strtw_a1),
                   s21_sscanf(str2, "%9ls %2ls", strtw_b, strtw_b1));
  ck_assert_mem_eq(strtw_a, strtw_b, 100);
  ck_assert_mem_eq(strtw_a1, strtw_b1, 100);
}
END_TEST

START_TEST(s21_sscanf_u_normal_signs_spec_test) {
  char str1[] = "95 4432 84884";
  char str2[] = "35d 5fg44444";
  char str3[] = "-54 +f +345";
  char str4[] = "  55    -444 g";
  unsigned int a = 0;
  unsigned int a1 = 0;
  unsigned int a2 = 0;
  unsigned int b = 0;
  unsigned int b1 = 0;
  unsigned int b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%u%u%u", &a, &a1, &a2),
                   s21_sscanf(str1, "%u%u%u", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%2u%4u%5u", &a, &a1, &a2),
                   s21_sscanf(str1, "%2u%4u%5u", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%10u %2u", &a, &a1),
                   s21_sscanf(str1, "%10u %2u", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str2, "%u%u %u", &a, &a1, &a2),
                   s21_sscanf(str2, "%u%u %u", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str3, " %u%u ", &a, &a1),
                   s21_sscanf(str3, " %u%u ", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str4, "%u %u", &a, &a1),
                   s21_sscanf(str4, "%u %u", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_u_width_length_spec_test) {
  char str1[] = "954432848 84";
  char str2[] = "32767";
  char str3[] = "4345";
  char str4[] = "2147483647  55";
  unsigned long int a = 0;
  unsigned short int a1 = 0;
  unsigned long int b = 0;
  unsigned short int b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%lu%hu", &a, &a1),
                   s21_sscanf(str1, "%lu%hu", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str2, "%hu", &a1), s21_sscanf(str2, "%hu", &b1));
  ck_assert_int_eq(a1, b1);
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str1, "%3hu %1lu", &a1, &a),
                   s21_sscanf(str1, "%3hu %1lu", &b1, &b));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str3, "%3hu %1lu", &a1, &a),
                   s21_sscanf(str3, "%3hu %1lu", &b1, &b));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str4, "%lu", &a), s21_sscanf(str4, "%lu", &b));
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str4, "%8lu %1hu", &a, &a1),
                   s21_sscanf(str4, "%8lu %1hu", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
}
END_TEST

START_TEST(s21_sscanf_xX_normal_signs_spec_test) {
  char str1[] = "0x12312FFFF2 +0X123";
  char str2[] = "0x0000 0xF";
  char str3[] = "0e44 -0x44 0xFFFFFFFF";

  unsigned int a = 0;
  unsigned int a1 = 0;
  unsigned int a2 = 0;
  unsigned int b = 0;
  unsigned int b1 = 0;
  unsigned int b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%x", &a), s21_sscanf(str1, "%x", &b));
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str1, "%X", &a), s21_sscanf(str1, "%X", &b));
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str1, "%x%X", &a, &a1),
                   s21_sscanf(str1, "%x%X", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str2, "%X%X", &a, &a1),
                   s21_sscanf(str2, "%X%X", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str3, "%x%X%x", &a, &a1, &a2),
                   s21_sscanf(str3, "%x%X%x", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;
}
END_TEST

START_TEST(s21_sscanf_xX_width_length_spec_test) {
  char str1[] = "0x12312FFFF2 +0X123";
  char str2[] = "0x0000 0xF";
  char str3[] = "0e44 -0x44 0xFFFFFFFF";

  unsigned int a = 0;
  unsigned short int a1 = 0;
  unsigned long int a2 = 0;
  unsigned int b = 0;
  unsigned short int b1 = 0;
  unsigned long int b2 = 0;

  ck_assert_int_eq(sscanf(str1, "%1x", &a), s21_sscanf(str1, "%1x", &b));
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str1, "%5X", &a), s21_sscanf(str1, "%5X", &b));
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;

  ck_assert_int_eq(sscanf(str1, "%3hx%4lX", &a1, &a2),
                   s21_sscanf(str1, "%3hx%4lX", &b1, &b2));
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;

  ck_assert_int_eq(sscanf(str2, "%6X%hX", &a, &a1),
                   s21_sscanf(str2, "%6X%hX", &b, &b1));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;

  ck_assert_int_eq(sscanf(str3, "%9x%9hX%9lx", &a, &a1, &a2),
                   s21_sscanf(str3, "%9x%9hX%9lx", &b, &b1, &b2));
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  a = 0;
  b = 0;
  a1 = 0;
  b1 = 0;
  a2 = 0;
  b2 = 0;
}
END_TEST

START_TEST(s21_sscanf_n_normal_spec_test) {
  char str_1[] = "123 456 789 0";
  char f1[] = "%n%d%d%d";
  char f2[] = "%d%n%d%d";
  char f3[] = "%1d%1d%1n%1d";
  char f4[] = "%3d%3d%3d%3n";
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_1, f1, &d1, &a1, &b1, &c1),
                   s21_sscanf(str_1, f1, &d2, &a2, &b2, &c2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_1, f2, &a1, &d1, &b1, &c1),
                   s21_sscanf(str_1, f2, &a2, &d2, &b2, &c2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_1, f3, &a1, &b1, &d1, &c1),
                   s21_sscanf(str_1, f3, &a2, &b2, &d2, &c2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str_1, f4, &a1, &b1, &c1, &d1),
                   s21_sscanf(str_1, f4, &a2, &b2, &c2, &d2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
}
END_TEST

START_TEST(s21_sscanf_n_invalid_spec_test) {
  char str_1[] = "dasklopk fjkdoskf osd";
  int a1 = 0, a2 = 0;
  char str_a[100] = {0};
  char str_a1[100] = {0};
  char str_b[100] = {0};
  char str_b1[100] = {0};

  ck_assert_int_eq(sscanf(str_1, "%s a %s%n", str_a, str_a1, &a1),
                   s21_sscanf(str_1, "%s a %s%n", str_b, str_b1, &a2));
  ck_assert_str_eq(str_a, str_b);
  ck_assert_str_eq(str_a1, str_b1);
  ck_assert_int_eq(a1, a2);
  for (int i = 0; i < 100; ++i) {
    str_a[i] = 0;
    str_b[i] = 0;
    str_a1[i] = 0;
    str_b1[i] = 0;
  }

  ck_assert_int_eq(
      sscanf(str_1, "%1s afdsfsd %1s%nfdsfa", str_a, str_a1, &a1),
      s21_sscanf(str_1, "%1s afdsfsd %1s%nfdsfa", str_b, str_b1, &a2));
  ck_assert_str_eq(str_a, str_b);
  ck_assert_str_eq(str_a1, str_b1);
  ck_assert_int_eq(a1, a2);
  for (int i = 0; i < 100; ++i) {
    str_a[i] = 0;
    str_b[i] = 0;
    str_a1[i] = 0;
    str_b1[i] = 0;
  }

  ck_assert_int_eq(sscanf(str_1, "%10c a %3c%n", str_a, str_a1, &a1),
                   s21_sscanf(str_1, "%10c a %3c%n", str_b, str_b1, &a2));
  ck_assert_str_eq(str_a, str_b);
  ck_assert_str_eq(str_a1, str_b1);
  ck_assert_int_eq(a1, a2);
  for (int i = 0; i < 100; ++i) {
    str_a[i] = 0;
    str_b[i] = 0;
    str_a1[i] = 0;
    str_b1[i] = 0;
  }
}
END_TEST

START_TEST(s21_sscanf_p_normal_spec_test) {
  char str1[] = "0xFFFF 0xAAAA 0x0000 0xBBC1FF";
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  ck_assert_int_eq(sscanf(str1, "%p%p%p%p", &a2, &b2, &c2, &d2),
                   s21_sscanf(str1, "%p%p%p%p", &a1, &b1, &c1, &d1));
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
  a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ck_assert_int_eq(sscanf(str1, "%p %p %p%p", &a2, &b2, &c2, &d2),
                   s21_sscanf(str1, "%p %p %p%p", &a1, &b1, &c1, &d1));
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST