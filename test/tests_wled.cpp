/* tests - wled, dynamic generated file from tool */ 
#include "gtest/gtest.h" 
#include "example.h" 

#include <new> 
#include <stdio.h> 

#include <bits/stdc++.h> 

using namespace std; 

TEST(example, t1s1_asku) 
{ 
  int ret = 0; 
  const char *command = "cd ../tdd/tools/tests/wled; tdd_t_maint_v8 t1s1_asku " ; 
  ret = system(command); 
  ASSERT_EQ(ret, 0); 
  // ASSERT_EQ(ret, 1); 
} 

