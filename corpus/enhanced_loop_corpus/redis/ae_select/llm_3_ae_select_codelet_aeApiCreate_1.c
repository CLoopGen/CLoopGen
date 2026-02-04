#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int __i;
extern fd_set *__arr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2), processing even indices first, then odd
    size_t total_elements = sizeof(fd_set) / sizeof(__fd_mask);
    // Process even indices
    for (__i = 0; __i < total_elements; __i += 2)
        ((__arr)->__fds_bits)[__i] = 0;
    // Process odd indices
    for (__i = 1; __i < total_elements; __i += 2)
        ((__arr)->__fds_bits)[__i] = 0;
}
