#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *vec;
extern int q;
extern float mix[200];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse order (consecutive but backward) memory access
    // Changes access pattern from forward to backward, which may affect cache behavior and prefetching
    int q;
    for (q = Alphabet_size - 1; q >= 0; q--) {
        mix[q] = vec[q];
    }
}
