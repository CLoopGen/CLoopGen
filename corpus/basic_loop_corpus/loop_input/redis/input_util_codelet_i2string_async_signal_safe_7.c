#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *buf;
int ix;

static char data[16777216]; // 16MB buffer to ensure ~0.01s runtime

void init_vars() {
    buf = &data[15]; // Point to the 16th element from the end to allow 16 iterations with pre-decrement
    for (int i = 0; i < 16; ++i) {
        data[i] = "0123456789abcdef"[i];
    }
    // Fill the rest of the buffer to avoid uninitialized data issues
    for (int i = 16; i < 16777216; ++i) {
        data[i] = "0123456789abcdef"[i % 16];
    }
}