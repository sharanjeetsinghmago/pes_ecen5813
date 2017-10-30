#include <math.h>
#include <stdlib.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/circbuf.c"

void Inv_Pointer(void **state)
{ 
  size_t length = 8;
  CB_t * buff=malloc( sizeof(CB_t) );
  buff->ptr=NULL;
  CB_status status  =  CB_init(buff ,length); 
  assert_int_equal(status,success);
}

void Non_Initialized_Buffer(void **state)
{ 
  size_t length = 0;
  CB_t *buff=malloc( sizeof(CB_t) );
  buff->ptr = malloc( sizeof(uint8_t) * length );
  CB_status status =   CB_init(buff ,length); 
  assert_int_equal(status,success);
}

void Allcate_Free(void **state)
{ 
  size_t length = 8;
  CB_t * buff = malloc( sizeof(CB_t) );
  buff->ptr = malloc( sizeof (uint8_t) * length );
  CB_status status = CB_init(buff ,length); 
  assert_int_equal(status,success);
}

void ADD_REMOVE(void **state)
{ 
  size_t length = 8;
  CB_t * buff = malloc( sizeof(CB_t) );
  buff->ptr = malloc( sizeof (uint8_t) * length );
  CB_init(buff ,length); 
  uint8_t data =10;
  uint8_t *src;
  src = &data;
  CB_buffer_add_item(buff, data);
  CB_status status = CB_buffer_remove_item(buff,src);
  assert_int_equal(status,success);
}

void Buffer_Full(void **state)
{ 
  size_t length = 8;
  CB_t *buff = malloc( sizeof(CB_t) );
  buff->ptr = malloc( sizeof (uint8_t) * length );
  CB_init(buff ,length); 
  uint8_t i=0;
  uint8_t data =10;
  uint8_t *src;
  src = &data;
  for(i=0;i<length;i++)
  {
  CB_buffer_add_item(buff,data);
  }
  CB_status status = CB_is_full(buff);
  assert_int_equal(status,buffer_full);
}

void Buffer_Empty(void **state)
{ 
  size_t length = 8;
  CB_t *buff = malloc( sizeof(CB_t) );
  buff->ptr = malloc( sizeof (uint8_t) * length );
  
  CB_init(buff ,length); 
  uint8_t i=0;
  uint8_t data =10;
  uint8_t *src;
  src = &data;
  for(i=0;i<length;i++) 
  {
  CB_buffer_add_item(buff,data);
  }
  for(i=0;i<length;i++) 
  {
  CB_buffer_remove_item(buff,src);
  }
  CB_status status = CB_is_empty(buff);
  assert_int_equal(status,buffer_empty);
}

void Buffer_WA(void **state)
{ 
  size_t length = 8;
  CB_t * buff = malloc( sizeof(CB_t) );
  buff->ptr = malloc( sizeof (uint8_t) * length );
  CB_init(buff,length); 
  uint8_t i=0;
  uint8_t data =10;
  uint8_t *src;
  src = &data;
  for(i=0;i<length-1;i++)
  {
  CB_buffer_add_item(buff,data);
  }
  CB_status status =  CB_buffer_add_item(buff,data);
  assert_int_equal(status,success);
}

void Buffer_WR(void **state)
{ 
  size_t length = 8;
  CB_t * buff = malloc( sizeof(CB_t));
  buff->ptr = malloc( sizeof (uint8_t) * length );
  CB_init(buff,length); 
  uint8_t i=0;
  uint8_t data =10;
  uint8_t *src;
  src = &data;
  for(i=0;i<length;i++) 
  {
  CB_buffer_add_item(buff,data);
  }
  for(i=0;i<length-1;i++) 
  {
  CB_buffer_remove_item(buff,src);
  }
  CB_status status =   CB_buffer_remove_item(buff,src);
  assert_int_equal(status,success);
}

void Over_Fill(void **state)
{ 
  size_t length = 8;
  CB_t *buff = malloc( sizeof(CB_t) );
  buff->ptr = malloc( sizeof (uint8_t) * length );
  CB_init(buff ,length); 
  uint8_t i=0;
  uint8_t data =10;
  uint8_t *src;
  src = &data;
  for(i=0;i<length;i++) 
  {
  CB_buffer_add_item(buff,data);
  }
  CB_status status =  CB_buffer_add_item(buff,data);
  assert_int_equal(status,buffer_full);
}

void Over_Empty(void **state)
{ 
  size_t length = 8;
  CB_t * buff = malloc( sizeof(CB_t) );
  buff->ptr = malloc( sizeof (uint8_t) * length );
  CB_init(buff ,length); 
  uint8_t i=0;
  uint8_t data =10;
  uint8_t *src;
  src = &data;
  for(i=0;i<length;i++) 
  {
  CB_buffer_add_item(buff,data);
  }
  for(i=0;i<length;i++) 
  {
  CB_buffer_remove_item(buff,src);
  }
  CB_status status =   CB_buffer_remove_item(buff,src);
  assert_int_equal(status,buffer_empty);
}

int main(int argc, char **argv)
{
  const struct CMUnitTest tests[] = {
  cmocka_unit_test(Inv_Pointer),
  cmocka_unit_test(Non_Initialized_Buffer),
  cmocka_unit_test(Allcate_Free),
  cmocka_unit_test(ADD_REMOVE),
  cmocka_unit_test(Buffer_Full),
  cmocka_unit_test(Buffer_Empty),
  cmocka_unit_test(Buffer_WA),
  cmocka_unit_test(Buffer_WR),
  cmocka_unit_test(Over_Fill),
  cmocka_unit_test(Over_Empty)
  };


  return cmocka_run_group_tests(tests, NULL, NULL);
}
