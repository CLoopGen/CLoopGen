#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 262144; // ~256K elements to target ~0.01 sec runtime
uint32_t value = 0xABCDEF01;
char bits[33];
int i;

void init_vars() {
    // Ensure width does not exceed the buffer size of bits array
    if (width > 32) {
        width = 32;
    }
    value = 0xABCDEF01U;
    i = 0;
}