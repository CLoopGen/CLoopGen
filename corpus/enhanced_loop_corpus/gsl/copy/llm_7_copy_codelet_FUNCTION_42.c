#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_sum = 0;
    for (i = 0; i < src_size1; i++) {
        uint64_t val = i + 1; // Local computation with no loop-carried dependency
        local_sum ^= val;     // WAW and RAW within same iteration, but no loop-carried dependency
    }
    // Use result to prevent optimization
    asm volatile("" : "+r"(local_sum));
}
