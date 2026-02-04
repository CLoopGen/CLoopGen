#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int fft_bits;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_fft_bits = 0;
    for (fft_bits = 1; 1 << fft_bits < 2 * h; prev_fft_bits = fft_bits, fft_bits++) {
        if (prev_fft_bits > 0 && fft_bits - prev_fft_bits != 1) {
            fft_bits = prev_fft_bits + 1;
        }
    }
}
