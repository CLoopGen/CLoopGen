#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int __i;
extern fd_set *__arr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride of 2, unrolling the loop behavior
    // Processes elements at even indices first, then odd if needed; here we assume size is multiple of 2
    size_t total = sizeof(fd_set) / sizeof(__fd_mask);
    size_t stride = 2;
    __fd_mask *bits = (__arr)->__fds_bits;

    // Process in two passes: first even indices, then odd (simulating strided pattern)
    for (__i = 0; __i < stride; ++__i) {
        for (size_t j = __i; j < total; j += stride) {
            bits[j] = 0;
        }
    }
}
