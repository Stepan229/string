START_TEST(strchr_1) {
  char *str = "The best team is Dead end of evolution";
  char c = 'D';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_2) {
  char *str = "The best team is Dead end of evolution";
  char c = 'Z';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_3) {
  char *str = "The best team is \0Dead end of evolution";
  char c = 'D';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test) {
  char str1[] = "Hello frisometextnd";
  char str2[] = "qwertygdfsgdfsb";
  char str3[] = "hellohellohello";
  char symbol1 = ' ';
  char symbol2 = 'f';
  char symbol3 = '0';

  ck_assert_ptr_eq(s21_strchr(str1, symbol1), strchr(str1, symbol1));
  ck_assert_ptr_eq(s21_strchr(str2, symbol2), strchr(str2, symbol2));
  ck_assert_ptr_eq(s21_strchr(str3, symbol3), strchr(str3, symbol3));
}
END_TEST

START_TEST(strcspn_1) {
  char *str = "Raise of evolution";
  char *src = "of";
  ck_assert_int_eq(strcspn(str, src), s21_strcspn(str, src));
}
END_TEST

START_TEST(strcspn_2) {
  char *str = "Raise of evolution";
  char *src = "ZXV";
  ck_assert_int_eq(strcspn(str, src), s21_strcspn(str, src));
}
END_TEST

START_TEST(strcspn_3) {
  char *str = "Raise \0of evolution";
  char *src = "of";
  ck_assert_int_eq(strcspn(str, src), s21_strcspn(str, src));
}
END_TEST

START_TEST(strcspn_4) {
  char *str = "Raise of evolution";
  char *src = "of\0vlin";
  ck_assert_int_eq(strcspn(str, src), s21_strcspn(str, src));
}
END_TEST

START_TEST(strcspn_5) {
  char *str = "+7 999 123 45 78";
  char *src = "58463";
  ck_assert_int_eq(strcspn(str, src), s21_strcspn(str, src));
}
END_TEST

START_TEST(s21_strcspn_test) {
  char test_1[] = "Hello World!";
  char test_2[] = "Just a str\0ing";
  char test_3[] = "Hello frisometextnd";
  char symbols_1[] = "Wit";
  char symbols_2[] = "t";

  ck_assert_int_eq(s21_strcspn(test_1, symbols_1), strcspn(test_1, symbols_1));
  ck_assert_int_eq(s21_strcspn(test_2, symbols_1), strcspn(test_2, symbols_1));
  ck_assert_int_eq(s21_strcspn(test_3, symbols_2), strcspn(test_3, symbols_2));
}
END_TEST

START_TEST(strerror_1) {
  int err_num = -2;
  ck_assert_str_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST

START_TEST(strerror_2) {
  for (int i = 0; i < 134; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}

START_TEST(strerror_3) {
  int err_num = 150;
  ck_assert_str_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST

START_TEST(strlen_1) {
  char *str_1 = "TUpichOCK\0";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(strlen_2) {
  char *str_1 = "TUPICHOCK of \0 EVOLUTION";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(strlen_3) {
  char *str_1 = "\0";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(strlen_4) {
  char *str_1 =
      "TUPICHOCK ? ||| //!! :;;;: "
      " '' 312654\0";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(s21_strlen_test) {
  char test_1[] = "Hello World!";
  char test_2[] = "";
  char test_3[] = "     \0";
  char test_4[] = "Just a str\0ing";
  char test_5[] = "\t\0";
  char test_6[] = "strlen\0";
  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));
}
END_TEST

START_TEST(strncat_1) {
  s21_size_t n = 6;
  char str[128] = "";
  char s21_str[128] = "";
  char *src = "";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_2) {
  s21_size_t n = 2;
  char str[128] = "123456";
  char s21_str[128] = "123456";
  char *src = "Evolution";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_3) {
  s21_size_t n = 8;
  char str[128] = "The best team is - ";
  char s21_str[128] = "The best team is - ";
  char *src = "Dead End Of Evolution!!!";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_4) {
  s21_size_t n = 0;
  char str[128] = "";
  char s21_str[128] = "";
  char *src = "Evolution";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_5) {
  s21_size_t n = 9;
  char str[128] = "";
  char s21_str[128] = "";
  char *src = "Evolution";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_6) {
  s21_size_t n = 5;
  char str[128] = "Evolution";
  char s21_str[128] = "Evolution";
  char *src = "";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_7) {
  s21_size_t n = 5;
  char str[128] = "Evolu\0tion";
  char s21_str[128] = "Evolu\0tion";
  char *src = "end";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_8) {
  s21_size_t n = 1;
  char str[128] = "Evolution";
  char s21_str[128] = "Evolution";
  char *src = "\0";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncmp_1) {
  s21_size_t n = 5;
  char *str_1 = "Raise of evolution";
  char *str_2 = "Raise of evolution";
  int system = strncmp(str_1, str_2, n);
  int s21 = s21_strncmp(str_1, str_2, n);
  system > 1 ? system = 1 : system < -1 ? system = -1 : system;
  s21 > 1 ? s21 = 1 : s21 < -1 ? s21 = -1 : s21;
  ck_assert_int_eq(system, s21);
}
END_TEST

START_TEST(strncmp_2) {
  s21_size_t n = 3;
  char *str_1 = "";
  char *str_2 = "Raise of evolution";
  int system = strncmp(str_1, str_2, n);
  int s21 = s21_strncmp(str_1, str_2, n);
  system > 1 ? system = 1 : system < -1 ? system = -1 : system;
  s21 > 1 ? s21 = 1 : s21 < -1 ? s21 = -1 : s21;
  ck_assert_int_eq(system, s21);
}
END_TEST

START_TEST(strncmp_3) {
  s21_size_t n = 14;
  char *str_1 = "Raise of evolution";
  char *str_2 = "Raise of evolution";
  int system = strncmp(str_1, str_2, n);
  int s21 = s21_strncmp(str_1, str_2, n);
  system > 1 ? system = 1 : system < -1 ? system = -1 : system;
  s21 > 1 ? s21 = 1 : s21 < -1 ? s21 = -1 : s21;
  ck_assert_int_eq(system, s21);
}
END_TEST

START_TEST(strncmp_4) {
  s21_size_t n = 4;
  char *str_1 = "Raise of evolution";
  char *str_2 = "Raise of ";
  int system = strncmp(str_1, str_2, n);
  int s21 = s21_strncmp(str_1, str_2, n);
  system > 1 ? system = 1 : system < -1 ? system = -1 : system;
  s21 > 1 ? s21 = 1 : s21 < -1 ? s21 = -1 : s21;
  ck_assert_int_eq(system, s21);
}
END_TEST

START_TEST(s21_strncmp_test) {
  char str1[] = "Text 1";
  char str2[] = "Texc 2";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3) == 0,
                   strncmp(str1, str2, 3) == 0);
  ck_assert_int_eq(s21_strncmp(str1, str2, 7) < 0, strncmp(str1, str2, 7) == 0);
}
END_TEST

START_TEST(strncpy_1) {
  s21_size_t n = 4;
  char str[128] = "Evolution";
  char s21_str[128] = "Evolution";
  char *src = "Best!";
  ck_assert_pstr_eq(strncpy(str, src, n), s21_strncpy(s21_str, src, n));
}
END_TEST

START_TEST(strncpy_2) {
  s21_size_t n = 4;
  char str[128] = "Evolution";
  char s21_str[128] = "Evolution";
  char *src = "Be\0st!";
  ck_assert_pstr_eq(strncpy(str, src, n), s21_strncpy(s21_str, src, n));
}
END_TEST

START_TEST(strncpy_3) {
  s21_size_t n = 7;
  char str[128] = "+7 999 234 12 43";
  char s21_str[128] = "+7 999 234 12 43";
  char *src = "21564\0vfs003543";
  ck_assert_pstr_eq(strncpy(str, src, n), s21_strncpy(s21_str, src, n));
}
END_TEST

START_TEST(strncpy_4) {
  s21_size_t n = 0;
  char str[128] = "";
  char s21_str[128] = "";
  char *src = "";
  ck_assert_pstr_eq(strncpy(str, src, n), s21_strncpy(s21_str, src, n));
}
END_TEST

START_TEST(strncpy_5) {
  s21_size_t n = 0;
  char str[128] = "Evolution";
  char s21_str[128] = "Evolution";
  char *src = "Best!";
  ck_assert_pstr_eq(strncpy(str, src, n), s21_strncpy(s21_str, src, n));
}
END_TEST

START_TEST(strncpy_6) {
  s21_size_t n = 5;
  char str[128] = "Evolution";
  char s21_str[128] = "Evolution";
  char *src = "";
  ck_assert_pstr_eq(strncpy(str, src, n), s21_strncpy(s21_str, src, n));
}
END_TEST

START_TEST(strpbrk_1) {
  char *str = "Dead end of evolution";
  char *src = "dev";
  ck_assert_pstr_eq(strpbrk(str, src), s21_strpbrk(str, src));
}
END_TEST

START_TEST(strpbrk_2) {
  char *str = "Dead end of evolution";
  char *src = "";
  ck_assert_pstr_eq(strpbrk(str, src), s21_strpbrk(str, src));
}
END_TEST

START_TEST(strpbrk_3) {
  char *str = "";
  char *src = "dev";
  ck_assert_pstr_eq(strpbrk(str, src), s21_strpbrk(str, src));
}
END_TEST

START_TEST(strpbrk_4) {
  char *str = "Raise of evolution";
  char *src = "465";
  ck_assert_pstr_eq(strpbrk(str, src), s21_strpbrk(str, src));
}
END_TEST

START_TEST(strpbrk_5) {
  char *str = "Raise of evolution";
  char *src = "/0";
  ck_assert_pstr_eq(strpbrk(str, src), s21_strpbrk(str, src));
}
END_TEST

START_TEST(strpbrk_6) {
  char *str = "Raise of Evolution";
  char *src = "rAISeVOl";
  ck_assert_pstr_eq(strpbrk(str, src), s21_strpbrk(str, src));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str1[] = "Hello frisometextnd";
  char str2[] = "qwertygdfsgdfsb";
  char str3[] = "hellohellohello";
  char str4[] = "ohe";
  char str5[] = "db";
  char str6[] = "";

  ck_assert_ptr_eq(s21_strpbrk(str1, str4), strpbrk(str1, str4));
  ck_assert_ptr_eq(s21_strpbrk(str2, str5), strpbrk(str2, str5));
  ck_assert_ptr_eq(s21_strpbrk(str2, str4), strpbrk(str2, str4));
  ck_assert_ptr_eq(s21_strpbrk(str3, str6), strpbrk(str3, str6));
  ck_assert_ptr_eq(s21_strpbrk(str1, "z"), strpbrk(str1, "z"));
}
END_TEST

START_TEST(strrchr_1) {
  char *str = "Raise of evolution";
  char c = 'o';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_2) {
  char *str = "Raise \0of evolution";
  char c = 'o';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_3) {
  char *str = "Raise of \0evolution";
  char c = 'o';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_4) {
  char *str = "Raise of evolution";
  char c = '\0';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_5) {
  char *str = "Raise of evolution";
  char c = 'Z';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_6) {
  char *str = "Raise of evolution";
  char c = 'Z';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_7) {
  char *str = "";
  char c = 'D';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_8) {
  char *str = "+7 999 45 54";
  char c = '4';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char str1[] = "Hello frisometextnd";
  char str2[] = "qwertygdfsgdfsb";
  char str3[] = "hellohellohello";
  char symbol1 = ' ';
  char symbol2 = 'e';
  char symbol3 = '0';

  ck_assert_ptr_eq(s21_strrchr(str1, symbol1), strrchr(str1, symbol1));
  ck_assert_ptr_eq(s21_strrchr(str2, symbol2), strrchr(str2, symbol2));
  ck_assert_ptr_eq(s21_strrchr(str3, symbol3), strrchr(str3, symbol3));
}
END_TEST

START_TEST(strstr_1) {
  char *str = "Dead end of evolution is the best team!";
  char *needle = "st te";
  ck_assert_pstr_eq(strstr(str, needle), s21_strstr(str, needle));
}
END_TEST

START_TEST(strstr_2) {
  char *str = "Dead end of evolution is the best team!";
  char *needle = " is \0the";
  ck_assert_pstr_eq(strstr(str, needle), s21_strstr(str, needle));
}
END_TEST

START_TEST(strstr_3) {
  char *str = "";
  char *needle = "st te";
  ck_assert_pstr_eq(strstr(str, needle), s21_strstr(str, needle));
}
END_TEST

START_TEST(strstr_4) {
  char *str = "Dead end of evolu\0tion is the best team!";
  char *needle = "the";
  ck_assert_pstr_eq(strstr(str, needle), s21_strstr(str, needle));
}
END_TEST

START_TEST(strstr_5) {
  char *str = "Dead end of evolution is the best team!";
  char *needle = "";
  ck_assert_pstr_eq(strstr(str, needle), s21_strstr(str, needle));
}
END_TEST

START_TEST(strstr_6) {
  char *str = "";
  char *needle = "";
  ck_assert_pstr_eq(strstr(str, needle), s21_strstr(str, needle));
}
END_TEST

START_TEST(s21_strstr_test) {
  char str1[] = "Hello frisometextnd";
  char str2[] = "text";
  char str3[] = "";
  char str4[] = "hellohellohello";
  char str5[] = "hello";

  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  ck_assert_ptr_eq(s21_strstr(str1, str3), strstr(str1, str3));
  ck_assert_ptr_eq(s21_strstr(str4, str5), strstr(str4, str5));
  ck_assert_ptr_eq(s21_strstr(str4, str2), strstr(str4, str2));
  ck_assert_ptr_eq(s21_strstr(str3, str4), strstr(str3, str4));
}
END_TEST

START_TEST(strtok_1) {
  char str[] = "Raise,of/Evolution the/best team";
  char s21_str[] = "Raise,of/Evolution the/best team";
  const char delim[] = ", /";
  char *system = strtok(str, delim);
  char *s21 = s21_strtok(s21_str, delim);
  ck_assert_uint_eq(s21_strlen(system), s21_strlen(s21));
  ck_assert_str_eq(system, s21);
  while (system && s21) {
    system = strtok(s21_NULL, delim);
    s21 = s21_strtok(s21_NULL, delim);
    if (system || s21) {
      ck_assert_str_eq(system, s21);
    } else {
      ck_assert_ptr_null(system);
      ck_assert_ptr_null(s21);
    }
  }
}
END_TEST

START_TEST(strtok_2) {
  char str[] = "Raise,of////Evolution    the+=best---==++team?in??the.world";
  char s21_str[] =
      "Raise,of////Evolution    the+=best---==++team?in??the.world";
  const char delim[] = ", /+=-?";
  char *system = strtok(str, delim);
  char *s21 = s21_strtok(s21_str, delim);
  ck_assert_uint_eq(s21_strlen(system), s21_strlen(s21));
  ck_assert_str_eq(system, s21);
  while (system && s21) {
    system = strtok(s21_NULL, delim);
    s21 = s21_strtok(s21_NULL, delim);
    if (system || s21) {
      ck_assert_str_eq(system, s21);
    } else {
      ck_assert_ptr_null(system);
      ck_assert_ptr_null(s21);
    }
  }
}
END_TEST

START_TEST(strtok_3) {
  char str[] = "RaiseofEvolutionthebestteam";
  char s21_str[] = "RaiseofEvolutionthebestteam";
  const char delim[] = ", /";
  char *system = strtok(str, delim);
  char *s21 = s21_strtok(s21_str, delim);
  ck_assert_uint_eq(s21_strlen(system), s21_strlen(s21));
  ck_assert_str_eq(system, s21);
  while (system && s21) {
    system = strtok(s21_NULL, delim);
    s21 = s21_strtok(s21_NULL, delim);
    ck_assert_ptr_null(system);
    ck_assert_ptr_null(s21);
  }
}
END_TEST

START_TEST(strtok_4) {
  char str[] = "====Evolution======";
  char s21_str[] = "====Evolution======";
  const char delim[] = ", /+=-?";
  char *system = strtok(str, delim);
  char *s21 = s21_strtok(s21_str, delim);
  ck_assert_uint_eq(s21_strlen(system), s21_strlen(s21));
  ck_assert_str_eq(system, s21);
  while (system && s21) {
    system = strtok(s21_NULL, delim);
    s21 = s21_strtok(s21_NULL, delim);
    ck_assert_ptr_null(system);
    ck_assert_ptr_null(s21);
  }
}
END_TEST

START_TEST(strtok_5) {
  char str[] = "+    +A+a+B+D++F";
  char s21_str[] = "+    +A+a+B+D++F";
  const char delim[] = ", /+=-?";
  char *system = strtok(str, delim);
  char *s21 = s21_strtok(s21_str, delim);
  ck_assert_uint_eq(s21_strlen(system), s21_strlen(s21));
  ck_assert_str_eq(system, s21);
  while (system && s21) {
    system = strtok(s21_NULL, delim);
    s21 = s21_strtok(s21_NULL, delim);
    if (system || s21) {
      ck_assert_str_eq(system, s21);
    } else {
      ck_assert_ptr_null(system);
      ck_assert_ptr_null(s21);
    }
  }
}
END_TEST

START_TEST(s21_strtok_test) {
  char str1[] = "Hello! fris.ometext!nd";
  char str1_copy[] = "Hello! fris.ometext!nd";
  char str2[] = "qwertygdfsgdfsb";
  char str3[] = "hellhelhello";
  char str3_copy[] = "hellhelhello";
  char delim1[] = "!.";
  char delim2[] = "";
  char delim3[] = "o";

  ck_assert_str_eq(s21_strtok(str1, delim1), strtok(str1_copy, delim1));
  ck_assert_str_eq(s21_strtok(s21_NULL, delim1), strtok(s21_NULL, delim1));
  ck_assert_ptr_eq(s21_strtok(str2, delim1), strtok(str2, delim1));
  ck_assert_ptr_eq(s21_strtok(str2, delim2), strtok(str2, delim2));
  ck_assert_str_eq(s21_strtok(str3, delim3), strtok(str3_copy, delim3));
  ck_assert_ptr_eq(s21_strtok(s21_NULL, delim3), strtok(s21_NULL, delim3));
  ck_assert_ptr_eq(s21_strtok(s21_NULL, ""), strtok(s21_NULL, ""));
}
END_TEST

START_TEST(s21_strerror_test) {
  for (int i = -5; i < 150; ++i) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST