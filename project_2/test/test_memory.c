#include <math.h>
#include <stdlib.h>
#include <stdint.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/memory.c"

void test_pointer_equal_NULL1(void **state)
{ 
  uint8_t * src = NULL;
  uint8_t * dst = NULL;
  size_t length = 10;
  memory_status status = my_memmove(src,dst,length);
  assert_int_equal(status,INVALID_POINTER_EQUALS_NULL);
}

void test_src_in_dst_overlap(void **state)
{ 
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  uint8_t * src = arr;
  uint8_t * dst = arr+9;
  size_t length = 10;
  memory_status status = my_memmove(src,dst,length);
  assert_int_equal(status,SUCCESS);
}

void test_dst_in_src_overlap(void **state)
{ 
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  uint8_t * src = arr+9;
  uint8_t * dst = arr;
  size_t length = 10;
  memory_status status = my_memmove(src,dst,length);
  assert_int_equal(status,SUCCESS);
}

void test_no_overlap(void **state)
{ 
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  uint8_t * src = arr;
  uint8_t * dst = arr+11;
  size_t length = 10;
  memory_status status = my_memmove(src,dst,length);
  assert_int_equal(status,SUCCESS);
}

void test_pointer_equal_NULL2(void **state)
{ 
  uint8_t * src = NULL;
  uint8_t value = 10;
  size_t length = 5;
  memory_status status = my_memset(src,length,value);
  assert_int_equal(status,INVALID_POINTER_EQUALS_NULL);
}

void test_CHECK_SET1(void **state)
{ 
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  uint8_t * src = arr;
  uint8_t value = 11;
  size_t length = 10;
  memory_status status = my_memset(src,length,value);
  assert_int_equal(status,SUCCESS);
}

void test_pointer_equal_NULL3(void **state)
{ 
  uint8_t * src = NULL;
  size_t length = 0;
  memory_status status = my_memzero(src,length);
  assert_int_equal(status,INVALID_POINTER_EQUALS_NULL);
}

void test_CHECK_SET2(void **state)
{ 
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  uint8_t * src = arr;
  uint8_t value = 11;
  size_t length = 10;
  memory_status status = my_memset(src,length,value);
  assert_int_equal(status,SUCCESS);
}

void test_pointer_equal_NULL4(void **state)
{ 
  uint8_t * src = NULL;
  size_t length = 0;
  memory_status status = my_reverse(src,length);
  assert_int_equal(status,INVALID_POINTER_EQUALS_NULL);
}

void CHECK_EVEN(void **state)
{ 
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  uint8_t * src = arr;
  size_t length = 10;
  memory_status status = my_reverse(src,length);
  assert_int_equal(status,SUCCESS);
}

void CHECK_ODD(void **state)
{ 
  int8_t arr[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
  uint8_t * src = arr;
  size_t length = 9;
  memory_status status = my_reverse(src,length);
  assert_int_equal(status,SUCCESS);
}

void CHECK_CHAR(void **state)
{ 
  int8_t arr[3]={'a','b','c'};
  uint8_t * src = arr;
  size_t length = 3;
  memory_status status = my_reverse(src,length);
  assert_int_equal(status,SUCCESS);
}


int main(int argc, char **argv)
{
  const struct CMUnitTest tests[] = {
  cmocka_unit_test(test_pointer_equal_NULL1),
  cmocka_unit_test(test_src_in_dst_overlap),
  cmocka_unit_test(test_dst_in_src_overlap),
  cmocka_unit_test(test_no_overlap),
  cmocka_unit_test(test_pointer_equal_NULL2),
  cmocka_unit_test(test_CHECK_SET1),
  cmocka_unit_test(test_pointer_equal_NULL3),
  cmocka_unit_test(test_CHECK_SET2),
  cmocka_unit_test(test_pointer_equal_NULL4),
  cmocka_unit_test(CHECK_EVEN),
  cmocka_unit_test(CHECK_ODD),
 cmocka_unit_test(CHECK_CHAR),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
