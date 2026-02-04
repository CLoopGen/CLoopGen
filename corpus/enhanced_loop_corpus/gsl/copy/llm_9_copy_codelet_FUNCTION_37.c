#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size1 * 2; i++) {
        volatile size_t idx = (i * 7) % src_size1;
        uint64_t acc = 0;
        acc += idx * 2 + 1;
        acc *= acc;
        if (acc > 1000) {
            acc /= 2;
        }
    }
}
