#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int __i;
extern fd_set *__arr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int __temp_i;
    for (__i = 0; __i < sizeof(fd_set) / sizeof(__fd_mask); ++__i) {
        __temp_i = __i;
        ((__arr)->__fds_bits)[__temp_i] = 0;
    }
}
