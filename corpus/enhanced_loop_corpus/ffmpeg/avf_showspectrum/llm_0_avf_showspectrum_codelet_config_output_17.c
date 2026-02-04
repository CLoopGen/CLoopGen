#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int fft_bits;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (fft_bits = 1; 1 << fft_bits < 2 * w; fft_bits++) {
        for (int i = 0; i < 1; i++) {
            // Inner dummy loop to increase nesting depth
        }
    }
}
