#include "gtest/gtest.h"
#include "example.h"

// #include <iostream>
#include <new>
#include <stdio.h>
// using namespace std

TEST(example, memcpy_cpu_cycles_1500)
{
    double res;
    res = add_numbers(1.0, 2.0);
    ASSERT_NEAR(res, 3.0, 1.0e-11);
    const uint32_t mem_size = 1518; // 1 * 1024 * 1024;

    char * buf_src = new char[mem_size];
    char * buf_dst = new char[mem_size];

    memcpy(buf_dst, buf_src, mem_size);

    delete [] buf_src;
    
    delete [] buf_dst;

}

TEST(example, memcpy_cpu_cycles_1m)
{
    double res;
    res = add_numbers(1.0, 2.0);
    ASSERT_NEAR(res, 3.0, 1.0e-11);
    const uint32_t mem_size = 1 * 1024 * 1024;

    char * buf_src = new char[mem_size];
    char * buf_dst = new char[mem_size];

    memcpy(buf_dst, buf_src, mem_size);

    delete [] buf_src;
    
    delete [] buf_dst;

}

TEST(example, memcpy_cpu_cycles_6m)
{
    double res;
    res = add_numbers(1.0, 2.0);
    ASSERT_NEAR(res, 3.0, 1.0e-11);
    const uint32_t mem_size = 6 * 1024 * 1024;

    char * buf_src = new char[mem_size];
    char * buf_dst = new char[mem_size];

    memcpy(buf_dst, buf_src, mem_size);

    delete [] buf_src;
    
    delete [] buf_dst;

}
