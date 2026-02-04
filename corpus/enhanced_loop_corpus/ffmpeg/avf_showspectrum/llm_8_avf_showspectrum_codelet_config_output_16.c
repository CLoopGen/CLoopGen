#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int fft_bits;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (fft_bits = 0; (1 << fft_bits) <= 2 * h + 1; fft_bits++) {
        fft_bits += (fft_bits & 1); // Increases arithmetic operations per iteration and slightly alters trip count
    }
}
