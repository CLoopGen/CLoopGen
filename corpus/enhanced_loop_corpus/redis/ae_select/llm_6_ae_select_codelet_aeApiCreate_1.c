#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int __i;
extern fd_set *__arr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t num_elements = sizeof(fd_set) / sizeof(__fd_mask);
    for (__i = 0; __i < num_elements; ++__i)
        ((__arr)->__fds_bits)[__i] = ((__arr)->__fds_bits)[__i] & 0;
}
