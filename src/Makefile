CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
CHECK_FLAGS = -lcheck
CHECK_FLAGS_LINUX = -lsubunit -lm
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
C_FILES = s21_mem.c \
		s21_str.c \
		s21_strerror.c \
		s21_trim.c \
		s21_to_lower.c \
		s21_to_upper.c \
		s21_insert.c \
		s21_sprintf.c \
		s21_sscanf.c

OBJ_FILES = $(C_FILES:.c=.o)
TF_NAME = s21_stringlib_tests
LIB_NAME = s21_string.a
OUT_RES_NAME = tests
OS=$(shell uname -s)

ifeq ($(OS), Linux)
 CC += -D OS_LINUX
endif

ifeq ($(OS), Darwin)
 CC += -D OS_MAC
endif


%.o: %.c
	$(CC) $(CFLAGS) -c $< 

all: $(LIB_NAME)
	make test

test: $(OBJ_FILES) $(TF_NAME).c $(LIB_NAME)
ifeq ($(OS), Linux)
	$(CC) $(CFLAGS) $(TF_NAME).c -o $(OUT_RES_NAME) $(CHECK_FLAGS) $(CHECK_FLAGS_LINUX) $(LIB_NAME)
else
	$(CC) $(CFLAGS) $(TF_NAME).c -o $(OUT_RES_NAME) $(CHECK_FLAGS) $(LIB_NAME)
endif
	make clean

$(LIB_NAME): $(OBJ_FILES) 
	ar rc $(LIB_NAME) $(OBJ_FILES)
	ranlib $(LIB_NAME)
	make clean

clean:
	rm -rf $(OBJ_FILES)
	rm -rf *.o

clean_all:
	rm -rf $(OBJ_FILES)
	rm -rf *.a
	rm -rf *.o
	rm -rf $(TF_NAME)
	rm -rf $(OUT_RES_NAME)
	rm -rf *.info
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf ./report

gcov_report: s21_string.a $(TF_NAME).c
ifeq ($(OS), Linux)
	$(CC) $(CFLAGS) $(TF_NAME).c -o $(OUT_RES_NAME) $(CHECK_FLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS_LINUX) $(LIB_NAME)
else
	$(CC) $(CFLAGS) $(TF_NAME).c -o $(OUT_RES_NAME) $(CHECK_FLAGS) $(GCOV_FLAGS) $(LIB_NAME)
endif
	./$(OUT_RES_NAME)
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o report/ Coverage_Report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov
	open ./report/index-sort-f.html

style_check:
	clang-format --style=Google -n *.c *.h tests_lib/*.h

style_fix: 
	clang-format --style=Google -i *.c *.h tests_lib/*.h

rebuild: clean_all all

run_test: 
	./$(OUT_RES_NAME)