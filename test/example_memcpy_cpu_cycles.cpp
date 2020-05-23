#include "gtest/gtest.h"
#include "example.h"

#include <new>
#include <stdio.h>

int memcpy_cpu_time(int mem_size)
{
    // double res;
    // res = add_numbers(1.0, 2.0);
    // ASSERT_NEAR(res, 3.0, 1.0e-11);

    // const uint32_t mem_size = 1518; // 1 * 1024 * 1024;

    char * buf_src = new char[mem_size];
    char * buf_dst = new char[mem_size];

    memcpy(buf_dst, buf_src, mem_size);

    delete [] buf_src;
    
    delete [] buf_dst;

    return 0;
}

TEST(example, memcpy_cpu_cycles_1500)
{
    const uint32_t mem_size = 1518; // 1 * 1024 * 1024;

    memcpy_cpu_time(mem_size);
}

TEST(example, memcpy_cpu_cycles_32kb)
{
    const uint32_t mem_size = 32 * 1024;

    memcpy_cpu_time(mem_size);
}

TEST(example, memcpy_cpu_cycles_128kb)
{
    const uint32_t mem_size = 128 * 1024;

    memcpy_cpu_time(mem_size);
}

TEST(example, memcpy_cpu_cycles_256kb)
{
    const uint32_t mem_size = 256 * 1024;

    memcpy_cpu_time(mem_size);
}

TEST(example, memcpy_cpu_cycles_1m)
{
    const uint32_t mem_size = 1 * 1024 * 1024;

    memcpy_cpu_time(mem_size);
}

TEST(example, memcpy_cpu_cycles_6m_call_sub)
{
    const uint32_t mem_size = 6 * 1024 * 1024;

    memcpy_cpu_time(mem_size);
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
