#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int __i;
extern fd_set *__arr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t total_elements = sizeof(fd_set) / sizeof(__fd_mask);
    for (__i = 0; __i < total_elements * 2; __i += 2) {
        if (__i < total_elements)
            ((__arr)->__fds_bits)[__i] = 0;
        if (__i + 1 < total_elements)
            ((__arr)->__fds_bits)[__i + 1] = 0;
    }
}
