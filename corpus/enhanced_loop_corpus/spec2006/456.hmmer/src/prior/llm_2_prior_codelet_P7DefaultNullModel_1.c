#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern float *null;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to handle even Alphabet_size
    int i;
    int stride = 2;
    int limit = Alphabet_size - (Alphabet_size % stride); // Make sure we don't overflow
    float inv_alphabet = 1.0f / (float)Alphabet_size;
    for (i = 0; i < limit; i += stride) {
        null[i] = inv_alphabet;
        if (i + 1 < Alphabet_size) {
            null[i + 1] = inv_alphabet;
        }
    }
    // Handle remaining element if Alphabet_size is odd
    if (limit < Alphabet_size) {
        null[limit] = inv_alphabet;
    }
}
