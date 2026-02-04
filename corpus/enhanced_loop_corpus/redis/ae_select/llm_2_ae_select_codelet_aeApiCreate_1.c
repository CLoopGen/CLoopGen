#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int __i;
extern fd_set *__arr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal
    for (__i = sizeof(fd_set) / sizeof(__fd_mask); __i > 0; )
        ((__arr)->__fds_bits)[--__i] = 0;
}
