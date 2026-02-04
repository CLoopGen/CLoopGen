#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int __i;
extern fd_set *__arr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile uint32_t prev = 0;
    uint32_t current;
    for (__i = 0; __i < sizeof(fd_set) / sizeof(__fd_mask); ++__i) {
        current = prev + ((__arr)->__fds_bits)[__i];
        ((__arr)->__fds_bits)[__i] = 0;
        prev = current;
    }
}
