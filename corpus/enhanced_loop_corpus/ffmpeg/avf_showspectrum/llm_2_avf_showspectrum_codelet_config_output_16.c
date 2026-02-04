#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int fft_bits;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile int* dummy_array = (volatile int*)malloc(sizeof(int) * 1024);
    for (fft_bits = 1; 1 << fft_bits < 2 * h; fft_bits++) {
        // Strided memory access pattern: write to every 4th element cyclically
        dummy_array[(fft_bits * 4) % 1024] += 1;
    }
    free((void*)dummy_array);
}
