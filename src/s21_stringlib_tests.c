#include <check.h>
#include <stdio.h>
#include <string.h>

#include "./s21_string.h"
#include "./tests_lib/tests_insert.h"
#include "./tests_lib/tests_mem.h"
#include "./tests_lib/tests_sprintf.h"
#include "./tests_lib/tests_sscanf.h"
#include "./tests_lib/tests_str.h"
#include "./tests_lib/tests_tolower.h"
#include "./tests_lib/tests_toupper.h"
#include "./tests_lib/tests_trim.h"

Suite *

s21_string_suite(void) {
  Suite *suite = suite_create("s21_string");
  TCase *tcase_core = tcase_create("s21_string");
  tcase_add_test(tcase_core, insert_1);
  tcase_add_test(tcase_core, insert_2);
  tcase_add_test(tcase_core, insert_3);
  tcase_add_test(tcase_core, insert_4);
  tcase_add_test(tcase_core, insert_5);
  tcase_add_test(tcase_core, insert_6);

  tcase_add_test(tcase_core, memchr_1);
  tcase_add_test(tcase_core, memchr_2);
  tcase_add_test(tcase_core, memchr_3);
  tcase_add_test(tcase_core, memchr_4);
  tcase_add_test(tcase_core, memchr_5);
  tcase_add_test(tcase_core, memchr_6);
  tcase_add_test(tcase_core, memchr_7);
  tcase_add_test(tcase_core, memchr_8);

  tcase_add_test(tcase_core, memcmp_1);
  tcase_add_test(tcase_core, memcmp_2);
  tcase_add_test(tcase_core, memcmp_3);

  tcase_add_test(tcase_core, memcpy_1);
  tcase_add_test(tcase_core, memcpy_2);
  tcase_add_test(tcase_core, memcpy_3);
  tcase_add_test(tcase_core, memcpy_4);

  tcase_add_test(tcase_core, memset_1);
  tcase_add_test(tcase_core, memset_2);
  tcase_add_test(tcase_core, memset_3);
  tcase_add_test(tcase_core, memset_4);
  tcase_add_test(tcase_core, memset_5);

  tcase_add_test(tcase_core, strchr_1);
  tcase_add_test(tcase_core, strchr_2);
  tcase_add_test(tcase_core, strchr_3);
  tcase_add_test(tcase_core, s21_strchr_test);

  tcase_add_test(tcase_core, strerror_1);
  tcase_add_test(tcase_core, strerror_2);
  tcase_add_test(tcase_core, strerror_3);

  tcase_add_test(tcase_core, strlen_1);
  tcase_add_test(tcase_core, strlen_2);
  tcase_add_test(tcase_core, strlen_3);
  tcase_add_test(tcase_core, strlen_4);
  tcase_add_test(tcase_core, s21_strlen_test);

  tcase_add_test(tcase_core, strcspn_1);
  tcase_add_test(tcase_core, strcspn_2);
  tcase_add_test(tcase_core, strcspn_3);
  tcase_add_test(tcase_core, strcspn_4);
  tcase_add_test(tcase_core, strcspn_5);
  tcase_add_test(tcase_core, s21_strcspn_test);

  tcase_add_test(tcase_core, strncat_1);
  tcase_add_test(tcase_core, strncat_2);
  tcase_add_test(tcase_core, strncat_3);
  tcase_add_test(tcase_core, strncat_4);
  tcase_add_test(tcase_core, strncat_5);
  tcase_add_test(tcase_core, strncat_6);
  tcase_add_test(tcase_core, strncat_7);
  tcase_add_test(tcase_core, strncat_8);

  tcase_add_test(tcase_core, strncmp_1);
  tcase_add_test(tcase_core, strncmp_2);
  tcase_add_test(tcase_core, strncmp_3);
  tcase_add_test(tcase_core, strncmp_4);
  tcase_add_test(tcase_core, s21_strncmp_test);

  tcase_add_test(tcase_core, strncpy_1);
  tcase_add_test(tcase_core, strncpy_2);
  tcase_add_test(tcase_core, strncpy_3);
  tcase_add_test(tcase_core, strncpy_4);
  tcase_add_test(tcase_core, strncpy_5);
  tcase_add_test(tcase_core, strncpy_6);

  tcase_add_test(tcase_core, strpbrk_1);
  tcase_add_test(tcase_core, strpbrk_2);
  tcase_add_test(tcase_core, strpbrk_3);
  tcase_add_test(tcase_core, strpbrk_4);
  tcase_add_test(tcase_core, strpbrk_5);
  tcase_add_test(tcase_core, strpbrk_6);
  tcase_add_test(tcase_core, s21_strpbrk_test);

  tcase_add_test(tcase_core, strrchr_1);
  tcase_add_test(tcase_core, strrchr_2);
  tcase_add_test(tcase_core, strrchr_3);
  tcase_add_test(tcase_core, strrchr_4);
  tcase_add_test(tcase_core, strrchr_5);
  tcase_add_test(tcase_core, strrchr_6);
  tcase_add_test(tcase_core, strrchr_7);
  tcase_add_test(tcase_core, strrchr_8);
  tcase_add_test(tcase_core, s21_strrchr_test);

  tcase_add_test(tcase_core, strstr_1);
  tcase_add_test(tcase_core, strstr_2);
  tcase_add_test(tcase_core, strstr_3);
  tcase_add_test(tcase_core, strstr_4);
  tcase_add_test(tcase_core, strstr_5);
  tcase_add_test(tcase_core, strstr_6);
  tcase_add_test(tcase_core, s21_strstr_test);

  tcase_add_test(tcase_core, strtok_1);
  tcase_add_test(tcase_core, strtok_2);
  tcase_add_test(tcase_core, strtok_3);
  tcase_add_test(tcase_core, strtok_4);
  tcase_add_test(tcase_core, strtok_5);
  tcase_add_test(tcase_core, s21_strtok_test);

  tcase_add_test(tcase_core, s21_strerror_test);

  tcase_add_test(tcase_core, to_lower_1);
  tcase_add_test(tcase_core, to_lower_2);
  tcase_add_test(tcase_core, to_lower_3);
  tcase_add_test(tcase_core, to_lower_4);

  tcase_add_test(tcase_core, to_upper_1);
  tcase_add_test(tcase_core, to_upper_2);
  tcase_add_test(tcase_core, to_upper_3);
  tcase_add_test(tcase_core, to_upper_4);

  tcase_add_test(tcase_core, trim_1);
  tcase_add_test(tcase_core, trim_2);
  tcase_add_test(tcase_core, trim_3);
  tcase_add_test(tcase_core, trim_4);
  tcase_add_test(tcase_core, trim_5);
  tcase_add_test(tcase_core, trim_6);
  tcase_add_test(tcase_core, s21_trim_test);

  tcase_add_test(tcase_core, sscanf_EOF1);
  tcase_add_test(tcase_core, sscanf_EOF2);
  tcase_add_test(tcase_core, sscanf_EOF3);
  tcase_add_test(tcase_core, sscanf_only_chars1);
  tcase_add_test(tcase_core, sscanf_only_chars2);
  tcase_add_test(tcase_core, sscanf_only_chars3);
  tcase_add_test(tcase_core, sscanf_only_chars4);
  tcase_add_test(tcase_core, sscanf_only_chars5);
  tcase_add_test(tcase_core, sscanf_special_symbols_as_chars1);
  tcase_add_test(tcase_core, sscanf_special_symbols_as_chars2);
  tcase_add_test(tcase_core, sscanf_special_symbols_as_chars3);
  tcase_add_test(tcase_core, sscanf_chars_flags1);
  tcase_add_test(tcase_core, sscanf_chars_flags2);
  tcase_add_test(tcase_core, sscanf_chars_flags3);
  tcase_add_test(tcase_core, sscanf_chars_aster1);
  tcase_add_test(tcase_core, sscanf_chars_aster2);
  tcase_add_test(tcase_core, sscanf_only_ints1);
  tcase_add_test(tcase_core, sscanf_only_ints2);
  tcase_add_test(tcase_core, sscanf_only_ints3);
  tcase_add_test(tcase_core, sscanf_ints_nwidth1);
  tcase_add_test(tcase_core, sscanf_ints_nwidth2);
  tcase_add_test(tcase_core, sscanf_ints_nwidth3);
  tcase_add_test(tcase_core, sscanf_ints_nwidth4);
  tcase_add_test(tcase_core, sscanf_ints_astwidth1);
  tcase_add_test(tcase_core, sscanf_ints_astwidth2);
  tcase_add_test(tcase_core, sscanf_ints_astwidth3);
  tcase_add_test(tcase_core, sscanf_ints_astwidth4);
  tcase_add_test(tcase_core, sscanf_signed_ints1);
  tcase_add_test(tcase_core, sscanf_signed_ints2);
  tcase_add_test(tcase_core, sscanf_signed_ints3);
  tcase_add_test(tcase_core, sscanf_signed_ints4);
  tcase_add_test(tcase_core, sscanf_spec_i_int1);
  tcase_add_test(tcase_core, sscanf_spec_i_int2);
  tcase_add_test(tcase_core, sscanf_spec_i_int3);
  tcase_add_test(tcase_core, sscanf_spec_i_int4);
  tcase_add_test(tcase_core, sscanf_spec_i_oct1);
  tcase_add_test(tcase_core, sscanf_spec_i_oct2);
  tcase_add_test(tcase_core, sscanf_spec_i_hex1);
  tcase_add_test(tcase_core, sscanf_spec_i_hex2);
  tcase_add_test(tcase_core, sscanf_strings1);
  tcase_add_test(tcase_core, sscanf_strings2);
  tcase_add_test(tcase_core, sscanf_strings3);
  tcase_add_test(tcase_core, sscanf_strings4);
  tcase_add_test(tcase_core, sscanf_strings5);
  tcase_add_test(tcase_core, sscanf_strings6);
  tcase_add_test(tcase_core, sscanf_uint1);
  tcase_add_test(tcase_core, sscanf_uint2);
  tcase_add_test(tcase_core, sscanf_uint3);
  tcase_add_test(tcase_core, sscanf_uint4);
  tcase_add_test(tcase_core, sscanf_uint5);
  tcase_add_test(tcase_core, sscanf_uint6);
  tcase_add_test(tcase_core, sscanf_strings_mixed1);
  tcase_add_test(tcase_core, sscanf_strings_mixed2);
  tcase_add_test(tcase_core, sscanf_strings_mixed3);
  tcase_add_test(tcase_core, sscanf_floats1);
  tcase_add_test(tcase_core, sscanf_floats2);
  tcase_add_test(tcase_core, sscanf_floats3);
  tcase_add_test(tcase_core, sscanf_floats4);
  tcase_add_test(tcase_core, sscanf_floats_sci3);
  tcase_add_test(tcase_core, sscanf_floats_sci4);
  tcase_add_test(tcase_core, sscanf_floats_sci5);
  tcase_add_test(tcase_core, sscanf_n1);
  tcase_add_test(tcase_core, sscanf_n2);
  tcase_add_test(tcase_core, sscanf_n3);
  tcase_add_test(tcase_core, sscanf_n4);
  tcase_add_test(tcase_core, sscanf_n5);
  tcase_add_test(tcase_core, sscanf_upeer_hex_base_version);
  tcase_add_test(tcase_core, sscanf_upeer_hex_overflow);
  tcase_add_test(tcase_core, sscanf_upeer_hex_0X);
  tcase_add_test(tcase_core, sscanf_upeer_hex_empty);
  tcase_add_test(tcase_core, sscanf_upeer_hex_fail);
  tcase_add_test(tcase_core, sscanf_upeer_hex_spaces_tabs_sns);
  tcase_add_test(tcase_core, sscanf_upeer_hex_short);
  tcase_add_test(tcase_core, sscanf_upeer_hex_long);
  tcase_add_test(tcase_core, sscanf_upeer_hex_longlong);
  tcase_add_test(tcase_core, sscanf_upeer_hex_2x);
  tcase_add_test(tcase_core, sscanf_upeer_hex_star);
  tcase_add_test(tcase_core, sscanf_upeer_hex_nohex);
  tcase_add_test(tcase_core, sscanf_upeer_hex_lower);
  tcase_add_test(tcase_core, sscanf_upeer_hex_sign);
  tcase_add_test(tcase_core, upper_hex_len);
  tcase_add_test(tcase_core, sscanf_lower_hex_base_version);
  tcase_add_test(tcase_core, sscanf_lower_hex_overflow);
  tcase_add_test(tcase_core, sscanf_lower_hex_0x);
  tcase_add_test(tcase_core, sscanf_lower_hex_empty);
  tcase_add_test(tcase_core, sscanf_lower_hex_fail);
  tcase_add_test(tcase_core, sscanf_lower_hex_spaces_tabs_sns);
  tcase_add_test(tcase_core, sscanf_lower_hex_short);
  tcase_add_test(tcase_core, sscanf_lower_hex_long);
  tcase_add_test(tcase_core, sscanf_lower_hex_longlong);
  tcase_add_test(tcase_core, sscanf_lower_hex_2x);
  tcase_add_test(tcase_core, sscanf_lower_hex_star);
  tcase_add_test(tcase_core, sscanf_lower_hex_nohex);
  tcase_add_test(tcase_core, sscanf_lower_hex_lower);
  tcase_add_test(tcase_core, sscanf_lower_hex_sign);
  tcase_add_test(tcase_core, sscanf_lower_hex_len);
  tcase_add_test(tcase_core, sscanf_octal_base_version);
  tcase_add_test(tcase_core, sscanf_octal_overflow);
  tcase_add_test(tcase_core, sscanf_octal_0x);
  tcase_add_test(tcase_core, sscanf_octal_0X);
  tcase_add_test(tcase_core, sscanf_octal_empty);
  tcase_add_test(tcase_core, sscanf_octal_fail);
  tcase_add_test(tcase_core, sscanf_octal_spaces_tabs_sns);
  tcase_add_test(tcase_core, sscanf_octal_short);
  tcase_add_test(tcase_core, sscanf_octal_long);
  tcase_add_test(tcase_core, sscanf_octal_longlong);
  tcase_add_test(tcase_core, sscanf_octal_2x);
  tcase_add_test(tcase_core, sscanf_octal_star);
  tcase_add_test(tcase_core, sscanf_octal_nohex);
  tcase_add_test(tcase_core, sscanf_octal_lower);
  tcase_add_test(tcase_core, sscanf_octal_sign);
  tcase_add_test(tcase_core, sscanf_octal_len);
  tcase_add_test(tcase_core, sscanf_pointer1);
  tcase_add_test(tcase_core, sscanf_buff1);
  tcase_add_test(tcase_core, sscanf_buff2);
  tcase_add_test(tcase_core, sscanf_mixed_ptrs1);
  tcase_add_test(tcase_core, sscanf_hard1);
  tcase_add_test(tcase_core, s21_sscanf_space_and_empty_test);
  tcase_add_test(tcase_core, s21_sscanf_suppress_test);
  tcase_add_test(tcase_core, s21_sscanf_c_normal_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_d_normal_signs_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_d_width_length_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_i_normal_signs_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_i_width_length_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_f_normal_sign_point_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_f_width_length_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_f_multi_dots_inf_nan_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_geGE_normal_sign_point_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_geGE_exp_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_geGE_width_length_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_geGE_multi_dots_inf_nan_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_o_normal_sign_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_o_width_length_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_s_normal_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_s_width_length_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_u_normal_signs_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_u_width_length_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_xX_normal_signs_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_xX_width_length_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_n_normal_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_n_invalid_spec_test);
  tcase_add_test(tcase_core, s21_sscanf_p_normal_spec_test);

  ///////////  end sscanf //////////////

  /////////  start sprintf //////////////
  tcase_add_test(tcase_core, sprintf_simple_int);
  tcase_add_test(tcase_core, sprintf_precise_int);
  tcase_add_test(tcase_core, sprintf_width_int);
  tcase_add_test(tcase_core, sprintf_minus_width_int);
  tcase_add_test(tcase_core, sprintf_plus_width_int);
  tcase_add_test(tcase_core, sprintf_padding_int);
  tcase_add_test(tcase_core, sprintf_star_width_int);
  tcase_add_test(tcase_core, sprintf_star_precision_int);
  tcase_add_test(tcase_core, sprintf_many_flags_many_ints);
  tcase_add_test(tcase_core, sprintf_flags_long_int);
  tcase_add_test(tcase_core, sprintf_flags_short_int);
  tcase_add_test(tcase_core, sprintf_flags_another_long_int);
  tcase_add_test(tcase_core, sprintf_zero_precision_zero_int);
  tcase_add_test(tcase_core, sprintf_space_flag_int);
  tcase_add_test(tcase_core, sprintf_unsigned_val);
  tcase_add_test(tcase_core, sprintf_unsigned_val_width);
  tcase_add_test(tcase_core, sprintf_unsigned_val_flags);
  tcase_add_test(tcase_core, sprintf_unsigned_val_precision);
  tcase_add_test(tcase_core, sprintf_unsigned_val_many_flags);
  tcase_add_test(tcase_core, sprintf_unsigned_val_short);
  tcase_add_test(tcase_core, sprintf_unsigned_val_long);
  tcase_add_test(tcase_core, sprintf_unsigned_val_many);

  tcase_add_test(tcase_core, sprintf_octal_width);
  tcase_add_test(tcase_core, sprintf_octal_flags);
  tcase_add_test(tcase_core, sprintf_octal_precision);
  tcase_add_test(tcase_core, sprintf_octal_many_flags);
  tcase_add_test(tcase_core, sprintf_octal_short);
  tcase_add_test(tcase_core, sprintf_octal_long);
  tcase_add_test(tcase_core, sprintf_octal_many);
  tcase_add_test(tcase_core, sprintf_octal);
  tcase_add_test(tcase_core, sprintf_octal_zero);
  tcase_add_test(tcase_core, sprintf_octal_hash);
  tcase_add_test(tcase_core, sprintf_unsigned_zero);
  tcase_add_test(tcase_core, sprintf_hex_width);
  tcase_add_test(tcase_core, sprintf_hex_flags);
  tcase_add_test(tcase_core, sprintf_hex_precision);
  tcase_add_test(tcase_core, sprintf_hex_many);
  tcase_add_test(tcase_core, sprintf_hex_many_flags);
  tcase_add_test(tcase_core, sprintf_hex_zero);
  tcase_add_test(tcase_core, sprintf_hex_huge);
  tcase_add_test(tcase_core, sprintf_hex_short);
  tcase_add_test(tcase_core, sprintf_hex_long);
  tcase_add_test(tcase_core, sprintf_hex_one_longer_width);
  tcase_add_test(tcase_core, sprintf_hex_two_longer_width);
  tcase_add_test(tcase_core, sprintf_one_char);
  tcase_add_test(tcase_core, sprintf_one_precision);
  tcase_add_test(tcase_core, sprintf_one_flags);
  tcase_add_test(tcase_core, sprintf_one_width);
  tcase_add_test(tcase_core, sprintf_one_many);
  tcase_add_test(tcase_core, sprintf_one_many_flags);
  tcase_add_test(tcase_core, sprintf_string);
  tcase_add_test(tcase_core, sprintf_string_precision);
  tcase_add_test(tcase_core, sprintf_string_width);
  tcase_add_test(tcase_core, sprintf_string_flags);
  tcase_add_test(tcase_core, sprintf_string_long);
  tcase_add_test(tcase_core, sprintf_string_many);
  tcase_add_test(tcase_core, sprintf_ptr);
  tcase_add_test(tcase_core, sprintf_ptr_width);
  tcase_add_test(tcase_core, sprintf_ptr_precision);
  tcase_add_test(tcase_core, sprintf_null_ptr);
  tcase_add_test(tcase_core, sprintf_n_specifier);
  tcase_add_test(tcase_core, sprintf_string_width_huge);
  tcase_add_test(tcase_core, sprintf_float_precision);
  tcase_add_test(tcase_core, sprintf_float_width);
  tcase_add_test(tcase_core, sprintf_float_precision_zero);
  tcase_add_test(tcase_core, sprintf_float_precision_empty);
  tcase_add_test(tcase_core, sprintf_float_precision_huge);
  tcase_add_test(tcase_core, sprintf_float_precision_huge_negative);
  tcase_add_test(tcase_core, sprintf_float_huge);
  tcase_add_test(tcase_core, sprintf_float_flags);
  tcase_add_test(tcase_core, sprintf_float_many);
  tcase_add_test(tcase_core, sprintf_e_precision);
  tcase_add_test(tcase_core, sprintf_e_precision_zero);
  tcase_add_test(tcase_core, sprintf_e_precision_empty);
  tcase_add_test(tcase_core, sprintf_e_precision_huge);
  tcase_add_test(tcase_core, sprintf_e_precision_huge_negative);
  tcase_add_test(tcase_core, sprintf_e_huge);
  tcase_add_test(tcase_core, sprintf_e_many);
  tcase_add_test(tcase_core, sprintf_e_width);
  tcase_add_test(tcase_core, sprintf_e_flags);
  tcase_add_test(tcase_core, sprintf_E_int);
  tcase_add_test(tcase_core, sprintf_all_empty);
  tcase_add_test(tcase_core, sprintf_empty_format_and_parameters);
  tcase_add_test(tcase_core, sprintf_test_one_char);
  tcase_add_test(tcase_core, sprintf_test_many_char);
  tcase_add_test(tcase_core, sprintf_test_one_string);
  tcase_add_test(tcase_core, sprintf_test_many_string);
  tcase_add_test(tcase_core, sprintf_test_one_dec);
  tcase_add_test(tcase_core, sprintf_test_many_dec);
  tcase_add_test(tcase_core, sprintf_test_one_int);
  tcase_add_test(tcase_core, sprintf_test_many_int);
  tcase_add_test(tcase_core, sprintf_test_one_float);
  tcase_add_test(tcase_core, sprintf_test_many_float);
  tcase_add_test(tcase_core, sprintf_test_one_unsigned_dec);
  tcase_add_test(tcase_core, sprintf_test_many_unsigned_dec);
  tcase_add_test(tcase_core, sprintf_test_one_char_with_alignment_left);
  tcase_add_test(tcase_core, sprintf_test_one_char_with_alignment_right);
  tcase_add_test(tcase_core, sprintf_test_many_char_with_alignment);
  tcase_add_test(tcase_core, sprintf_test_one_hex_lower);
  tcase_add_test(tcase_core, sprintf_test_one_hex_upper);
  tcase_add_test(tcase_core, sprintf_test_many_hex_lower);
  tcase_add_test(tcase_core, sprintf_test_many_hex_upper);
  tcase_add_test(tcase_core, sprintf_test_one_hex_lower_with_alignment_left);
  tcase_add_test(tcase_core, sprintf_test_one_hex_lower_with_alignment_right);
  tcase_add_test(tcase_core, sprintf_test_one_hex_upper_with_alignment_left);
  tcase_add_test(tcase_core, sprintf_test_one_hex_upper_with_alignment_right);
  tcase_add_test(tcase_core, sprintf_test_many_hex_lower_with_alignment);
  tcase_add_test(tcase_core, sprintf_test_many_hex_upper_with_alignment);
  tcase_add_test(tcase_core, sprintf_test_one_hex_with_hashtag);
  tcase_add_test(tcase_core, sprintf_test_one_hex_upper_with_hashtag);
  tcase_add_test(tcase_core,
                 sprintf_test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tcase_core,
                 sprintf_test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tcase_core, sprintf_test_one_hex_lower_with_width_star);
  tcase_add_test(tcase_core, sprintf_test_one_hex_upper_with_width_star);
  tcase_add_test(
      tcase_core,
      sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tcase_core, sprintf_test_many_hex_upper_with_width_star);
  tcase_add_test(tcase_core, sprintf_test_one_hex_lower_with_precision);
  tcase_add_test(tcase_core, sprintf_test_one_hex_upper_with_precision);
  tcase_add_test(tcase_core,
                 sprintf_test_many_hex_lower_with_precision_and_other);
  tcase_add_test(tcase_core,
                 sprintf_test_many_hex_upper_with_precision_and_other);
  tcase_add_test(tcase_core, sprintf_test_one_hex_lower_with_length);
  tcase_add_test(tcase_core, sprintf_test_one_hex_upper_with_length);
  tcase_add_test(tcase_core, sprintf_test_sprintf1);
  tcase_add_test(tcase_core, sprintf_test_sprintf2);
  tcase_add_test(tcase_core, sprintf_test_sprintf3);
  tcase_add_test(tcase_core, sprintf_test_sprintf4);
  tcase_add_test(tcase_core, sprintf_test_sprintf6);
  tcase_add_test(tcase_core, sprintf_test_sprintf7);
  tcase_add_test(tcase_core, sprintf_test_sprintf8);
  tcase_add_test(tcase_core, sprintf_test_sprintf9);
  tcase_add_test(tcase_core, sprintf_test_sprintf10);
  tcase_add_test(tcase_core, sprintf_test_sprintf11);
  tcase_add_test(tcase_core, sprintf_test_sprintf12);
  tcase_add_test(tcase_core, sprintf_test_sprintf15);
  tcase_add_test(tcase_core, sprintf_test_sprintf16);
  tcase_add_test(tcase_core, sprintf_test_sprintf17);
  tcase_add_test(tcase_core, sprintf_test_sprintf18);
  tcase_add_test(tcase_core, sprintf_test_sprintf19);
  tcase_add_test(tcase_core, sprintf_test_sprintf20);
  tcase_add_test(tcase_core, sprintf_test_sprintf24);
  tcase_add_test(tcase_core, sprintf_test_sprintf25);
  tcase_add_test(tcase_core, sprintf_test_sprintf26);
  tcase_add_test(tcase_core, sprintf_test_sprintf27);
  tcase_add_test(tcase_core, sprintf_test_sprintf28);
  tcase_add_test(tcase_core, sprintf_test_sprintf29);
  tcase_add_test(tcase_core, sprintf_test_sprintf30);
  tcase_add_test(tcase_core, sprintf_test_sprintf31);
  tcase_add_test(tcase_core, sprintf_test_sprintf32);
  tcase_add_test(tcase_core, sprintf_test_sprintf33);
  tcase_add_test(tcase_core, sprintf_test_sprintf35);
  tcase_add_test(tcase_core, sprintf_test_sprintf36);
  tcase_add_test(tcase_core, sprintf_test_sprintf37);
  tcase_add_test(tcase_core, sprintf_test_sprintf38);
  tcase_add_test(tcase_core, sprintf_test_sprintf39);
  tcase_add_test(tcase_core, sprintf_test_sprintf40);
  tcase_add_test(tcase_core, sprintf_test_sprintf41);
  tcase_add_test(tcase_core, sprintf_test_sprintf42);
  tcase_add_test(tcase_core, sprintf_test_sprintf43);
  tcase_add_test(tcase_core, sprintf_test_sprintf44);
  tcase_add_test(tcase_core, sprintf_test_sprintf45);
  tcase_add_test(tcase_core, sprintf_test_sprintf46);
  tcase_add_test(tcase_core, sprintf_test_sprintf47);
  tcase_add_test(tcase_core, sprintf_test_sprintf48);
  tcase_add_test(tcase_core, sprintf_test_sprintf49);
  tcase_add_test(tcase_core, sprintf_test_sprintf50);
  tcase_add_test(tcase_core, sprintf_g_trailing_zero);
  tcase_add_test(tcase_core, sprintf_g_large);
  tcase_add_test(tcase_core, sprintf_g_small);
  tcase_add_test(tcase_core, sprintf_g_precision);
  tcase_add_test(tcase_core, sprintf_g_precision_zero);
  tcase_add_test(tcase_core, sprintf_g_precision_missing);
  tcase_add_test(tcase_core, sprintf_g_many_zeroes_in_front);
  tcase_add_test(tcase_core, sprintf_g_one_zero);
  tcase_add_test(tcase_core, sprintf_g_mantiss);
  tcase_add_test(tcase_core, sprintf_g_mantiss_flags);
  tcase_add_test(tcase_core, sprintf_g_short_no_mantiss);
  tcase_add_test(tcase_core, sprintf_LG);
  tcase_add_test(tcase_core, sprintf_g_many);
  tcase_add_test(tcase_core, sprintf_g_zero);
  tcase_add_test(tcase_core, sprintf_wide_char);
  tcase_add_test(tcase_core, sprintf_width_char);
  tcase_add_test(tcase_core, sprintf_minus_wide_char);

  ///////////  end sprintf //////////////

  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  srunner_free(suite_runner);
  return 0;
}