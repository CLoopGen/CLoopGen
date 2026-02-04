#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *v1;
extern  int16_t *v2;
extern int length;
extern int scaling;
extern int64_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This accesses every second element of v1 and v2, reducing the total iterations by half
    // but maintaining coherence in memory access pattern (still sequential within stride)
    sum = 0;  // Reset sum for correctness
    int stride = 2;
    for (int i = 0; i < length; i += stride) {
        sum += (v1[i] * v2[i]) >> scaling;
    }
}
