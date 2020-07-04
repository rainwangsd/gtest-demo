#include "gtest/gtest.h"
#include "example.h"

#include <new>
#include <stdio.h>

#include <bits/stdc++.h> 
using namespace std; 
int tests_compile_execute () 
{ 
    char filename[100]; 
    cout << "Enter file name to compile "; 
    cin.getline(filename, 100); 
  
    // Build command to execute.  For example if the input 
    // file name is a.cpp, then str holds "gcc -o a.out a.cpp"  
    // Here -o is used to specify executable file name 
    string str = "gcc "; 
    str = str + " -o a.out " + filename; 
  
    // Convert string to const char * as system requires 
    // parameter of type const char * 
    const char *command = str.c_str(); 
  
    cout << "Compiling file using " << command << endl; 
    system(command); 
  
    cout << "\nRunning file "; 
    system("./a.out"); 
  
    return 0; 
} 

int tests_run_hello () 
{ 
    cout << "Hello World!" << endl; 

    const char *command = "ls";
    cout << "cmd: " << command << endl; 
    // system("tdd_t_maint_v8"); 
    system(command); 
    return 0; 
} 

// run tdd script
int tests_run_tdd () 
{ 
    int ret = 0;

    cout << "tests: " << endl; 
    
    const char *command = "tdd_t_maint_v8 ";
    cout << "cmd: " << command << endl; 
    ret = system(command); 

    cout << "ret: " << ret << endl; 
    return ret; 
} 

// test wled
// tdd/tools/tests/wled
int tests_run_tdd_wled () 
{ 
    int ret = 0;

    cout << "tests: " << endl; 
    
    const char *command = "cd ../tdd/tools/tests/wled;tdd_t_maint_v8 ";
    cout << "cmd: " << command << endl; 
    ret = system(command); 

    cout << "ret: " << ret << endl; 
    return ret; 
} 

TEST(example, tests_run_hello)
{   
    int ret = 0;
    ret = tests_run_hello();
    ASSERT_EQ(ret, 0);
    // ASSERT_EQ(ret, 1);
}

TEST(example, tests_run_tdd)
{   
    int ret = 0;
    ret = tests_run_tdd();
    ASSERT_EQ(ret, 0);
    // ASSERT_EQ(ret, 1);
}

TEST(example, tests_run_tdd_wled)
{   
    int ret = 0;
    ret = tests_run_tdd_wled();
    ASSERT_EQ(ret, 0);
    // ASSERT_EQ(ret, 1);
}

// TEST(example, memcpy_cpu_cycles_1500)
// {
//     const uint32_t mem_size = 1518; // 1 * 1024 * 1024;

//     memcpy_cpu_time(mem_size);
// }

// int memcpy_cpu_time(int mem_size)
// {
//     // double res;
//     // res = add_numbers(1.0, 2.0);
//     // ASSERT_NEAR(res, 3.0, 1.0e-11);

//     // const uint32_t mem_size = 1518; // 1 * 1024 * 1024;

//     char * buf_src = new char[mem_size];
//     char * buf_dst = new char[mem_size];

//     memcpy(buf_dst, buf_src, mem_size);

//     delete [] buf_src;
    
//     delete [] buf_dst;

//     return 0;
// }

// TEST(example, memcpy_cpu_cycles_1500)
// {
//     const uint32_t mem_size = 1518; // 1 * 1024 * 1024;

//     memcpy_cpu_time(mem_size);
// }

// TEST(example, memcpy_cpu_cycles_32kb)
// {
//     const uint32_t mem_size = 32 * 1024;

//     memcpy_cpu_time(mem_size);
// }

// TEST(example, memcpy_cpu_cycles_128kb)
// {
//     const uint32_t mem_size = 128 * 1024;

//     memcpy_cpu_time(mem_size);
// }

// TEST(example, memcpy_cpu_cycles_256kb)
// {
//     const uint32_t mem_size = 256 * 1024;

//     memcpy_cpu_time(mem_size);
// }

// TEST(example, memcpy_cpu_cycles_1m)
// {
//     const uint32_t mem_size = 1 * 1024 * 1024;

//     memcpy_cpu_time(mem_size);
// }

// TEST(example, memcpy_cpu_cycles_6m_call_sub)
// {
//     const uint32_t mem_size = 6 * 1024 * 1024;

//     memcpy_cpu_time(mem_size);
// }

// TEST(example, memcpy_cpu_cycles_6m)
// {
//     double res;
//     res = add_numbers(1.0, 2.0);
//     ASSERT_NEAR(res, 3.0, 1.0e-11);
//     const uint32_t mem_size = 6 * 1024 * 1024;

//     char * buf_src = new char[mem_size];
//     char * buf_dst = new char[mem_size];

//     memcpy(buf_dst, buf_src, mem_size);

//     delete [] buf_src;
    
//     delete [] buf_dst;
// }
