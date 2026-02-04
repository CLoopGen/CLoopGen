#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int fft_bits;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (fft_bits = 1; (1 << fft_bits) < 2 * w; fft_bits += 1) {
        // Introduce a dummy array to demonstrate memory access pattern modification
        int dummy_array[32];
        // Strided memory access: write every 2nd element based on loop index
        if (fft_bits < 32) {
            dummy_array[fft_bits * 2 % 32] = fft_bits;
        }
    }
}
