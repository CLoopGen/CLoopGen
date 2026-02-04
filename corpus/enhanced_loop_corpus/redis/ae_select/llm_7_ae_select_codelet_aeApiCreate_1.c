#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int __i;
extern fd_set *__arr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile uint32_t accumulator = 0;
    size_t count = sizeof(fd_set) / sizeof(__fd_mask);
    for (__i = 0; __i < count; ++__i) {
        accumulator += __i;
        ((__arr)->__fds_bits)[__i] = accumulator ^ accumulator; // introduces WAW and loop-carried dependency via accumulator, but semantically still assigns 0
    }
}
