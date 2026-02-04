#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int fft_bits;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_fft_bits = 1;
    for (fft_bits = 1; (1 << temp_fft_bits) < 2 * w; temp_fft_bits++) {
        fft_bits = temp_fft_bits;
    }
    fft_bits = temp_fft_bits;
}
