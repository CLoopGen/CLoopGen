#include <stdio.h>
#include <inttypes.h>

unsigned char key[131072]; // 128KB to ensure loop takes ~0.01 seconds
size_t i;

void init_vars() {
    // No additional initialization needed beyond zeroing global data
    // Global arrays are zero-initialized by default
}