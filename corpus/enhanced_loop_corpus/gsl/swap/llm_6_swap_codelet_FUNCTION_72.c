#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t dest_size1;
extern  size_t dest_size2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dest_size1; i++) {
    size_t j, k;
    for (j = 0; j < dest_size2; j++) {
        k = i + j;
        // Introduce a WAW and RAW dependency: each iteration writes to k, which is read in the next operation
        k *= 2;
        // Use k in a dummy volatile access to prevent optimization and preserve dependency
        __asm__ volatile("" : "+r"(k));
    }
}
}
