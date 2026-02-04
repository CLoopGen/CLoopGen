#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This accesses every second element in two passes to cover all indices
    for (x = 0; x < Alphabet_size; x += 2)
        null[x] = 0.25;
    for (x = 1; x < Alphabet_size; x += 2)
        null[x] = 0.25;
}
