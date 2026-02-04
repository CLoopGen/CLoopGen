#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int __i;
extern fd_set *__arr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile uint32_t prev = 0;
    size_t count = sizeof(fd_set) / sizeof(__fd_mask);
    for (__i = 0; __i < count; ++__i) {
        uint32_t temp = ((__arr)->__fds_bits)[__i];
        ((__arr)->__fds_bits)[__i] = prev;
        prev = temp;
    }
}
