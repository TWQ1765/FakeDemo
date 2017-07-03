#include "unity.h"
#include <stdio.h>
#include "mock_Add.h"

//fake 
int fake_add(int v1, int v2, int callNumber){
  printf("hello\n");
  if(callNumber == 0)       //ex1
    return 0;
  else if(callNumber == 1)  //ex2
    return 45;
  
  return -1;
}


void setUp(void)
{
 add_StubWithCallback(fake_add); // when call add please call fake_add
}
void tearDown(void)
{
}

//test add function
void test_Add_given_2_6_expect_8(void){
//* mock test will be fix */   
//  add_ExpectAndReturn(2, 6, 8);    // ex1 mock
//  add_ExpectAndReturn(9, 12, 21);  // ex2 mock
  
/* fake test not affect the input order & value.  
 * test will pass with the correct return value.
 * which is 0 & 45.
*/
  TEST_ASSERT_EQUAL(0, add(2,8));//ex1
  TEST_ASSERT_EQUAL(45, add(9,12));// ex2
}
