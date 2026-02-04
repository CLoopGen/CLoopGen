#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int __i;
extern fd_set *__arr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    __fd_mask *ptr = (__arr)->__fds_bits;
    for (__i = 0; __i < sizeof(fd_set) / sizeof(__fd_mask); ++__i)
        *(ptr + __i) = 0;
}
