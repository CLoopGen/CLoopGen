#include <stdio.h>

#include <inttypes.h>

extern float aafq[];
extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to handle even index pairs
    int i;
    for (i = 0; i < Alphabet_size; i += 2) {
        if (i < Alphabet_size) {
            null[i] = aafq[i];
        }
        if (i + 1 < Alphabet_size) {
            null[i + 1] = aafq[i + 1];
        }
    }
}
