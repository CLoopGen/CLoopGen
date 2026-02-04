#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t w = 256 * 1024 * 1024; // 256 million iterations for ~0.01 sec runtime
uint32_t v = 0xABCDEF99; // arbitrary non-zero value for bit testing
char bits[33]; // exactly 33 bytes as declared
int i;

void init_vars() {
    // Ensure that the loop condition `i < w - 1` does not cause out-of-bounds access to bits[33]
    // So we must have: w - 1 <= 32  => w <= 33
    // But original w is large, so we cap it appropriately for safe array access
    if (w > 33) {
        w = 33;
    }
    // Initialize v with predictable pattern if needed
    v = 0xABCDEF99;
    // Ensure bits array is safely initialized within bounds in case other code reads it
    for (int j = 0; j < 33; j++) {
        bits[j] = 'X'; // placeholder before loop processing
    }
    i = 0; // reset loop index
}