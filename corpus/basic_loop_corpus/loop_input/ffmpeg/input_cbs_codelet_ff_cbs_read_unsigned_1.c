#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 256 * 1024 * 1024; // 256 million iterations ~0.01 sec on modern CPU
uint32_t value = 0xDEADBEEF;
char bits[33]; // Only 33 bytes needed, as per declaration
int i;

void init_vars() {
    // Ensure width does not exceed the capacity of bits array minus one (for null terminator)
    if (width >= 33) {
        width = 32; // Max index used will be 32-1=31, leaving bits[32] for possible null
    }
    value = 0x87654321;
    // bits array is already defined with file scope, no dynamic init needed
    i = 0;
}