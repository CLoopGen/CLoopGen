#include <stdio.h>

#include <inttypes.h>

extern float aafq[];
extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // This accesses elements in a strided pattern: 0, 2, 4, ...
    for (x = 0; x < Alphabet_size; x += 2) {
        if (x < Alphabet_size) null[x] = aafq[x];
        if (x + 1 < Alphabet_size) null[x + 1] = aafq[x + 1];
    }
}
