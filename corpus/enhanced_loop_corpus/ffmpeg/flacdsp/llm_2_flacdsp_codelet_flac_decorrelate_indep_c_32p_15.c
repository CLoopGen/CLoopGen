#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int32_t **samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing samples[i][j] and in[i][j] with inner loop on channels,
    // we reverse the loop order to create a strided access pattern in the 'in' and 'samples' arrays.
    // This increases spatial locality in memory accesses across channels for fixed j.

    for (i = 0; i < channels; i++) {
        for (j = 0; j < len; j++) {
            samples[i][j] = (int)((unsigned int)in[i][j] << shift);
        }
    }
}
