#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int __i;
extern fd_set *__arr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const unsigned int step = 2;
    unsigned int limit = (sizeof(fd_set) / sizeof(__fd_mask) + step - 1) / step;
    for (__i = 0; __i < limit; ++__i) {
        unsigned int idx1 = __i * step;
        unsigned int idx2 = idx1 + 1;
        ((__arr)->__fds_bits)[idx1] = 0;
        if (idx2 < sizeof(fd_set) / sizeof(__fd_mask)) {
            ((__arr)->__fds_bits)[idx2] = 0;
        }
    }
}
