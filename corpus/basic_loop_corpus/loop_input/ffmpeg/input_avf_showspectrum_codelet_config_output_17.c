#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int fft_bits;
int w;

void init_vars() {
    w = 1 << 24; // Set w to 16,777,216 to make the loop run approximately 0.01 seconds
}

void loop(); // Forward declaration

// Entry point for other files to call loop()
void entry_point() {
    init_vars();
    loop();
}