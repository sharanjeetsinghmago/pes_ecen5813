#include <math.h>
#include <stdlib.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../include/common/conversion.h"
#include "../src/conversion.c"

void test_btol_null(void **state)
{
  uint32_t *data = NULL;
  uint32_t length = 32;
  conv_status status = big_to_little32(data,length);
  assert_int_equal(status,INVALID_POINTER_EQUALS_NULL);

}

void test_ltob(void **state)
{


  uint32_t arr[32] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x010,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x30,0x31,0x32};
 
  uint32_t *data = arr;
  uint32_t length = 32;
  conv_status status = big_to_little32(data,length); 
  assert_int_equal(status, VALID_CONVERSION);
}


void test_ltob_null(void **state)
{
  uint32_t *data = NULL;
  uint32_t length = 32;
  conv_status status = big_to_little32(data,length);
  assert_int_equal(status,INVALID_POINTER_EQUALS_NULL);

}

void test_btol(void **state)
{


  uint32_t arr[32] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x010,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x30,0x31,0x32};
 
  uint32_t *data = arr;
  uint32_t length = 32;
  conv_status status = big_to_little32(data,length); 
  assert_int_equal(status, VALID_CONVERSION);
}


int main(void)
{
  const struct CMUnitTest tests[] = 
  {
    cmocka_unit_test(test_btol_null),
    cmocka_unit_test(test_btol),
    cmocka_unit_test(test_ltob_null),
    cmocka_unit_test(test_ltob)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
