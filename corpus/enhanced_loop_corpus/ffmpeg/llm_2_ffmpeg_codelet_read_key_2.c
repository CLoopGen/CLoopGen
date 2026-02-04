#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int __i;
extern fd_set *__arr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic (forward traversal)
    __fd_mask *bits = (__arr)->__fds_bits;
    size_t count = sizeof(fd_set) / sizeof(__fd_mask);
    for (__i = 0; __i < count; ++__i) {
        *(bits + __i) = 0;
    }
}
