#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int fft_bits;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_w = w;
    int limit = 2 * local_w;
    int bit_power = 1;
    for (fft_bits = 1; bit_power < limit; fft_bits++) {
        bit_power = 1 << fft_bits;
    }
    if (bit_power >= limit) {
        fft_bits--;
    }
}
