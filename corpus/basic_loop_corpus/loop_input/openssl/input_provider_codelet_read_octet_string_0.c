#include <stdint.h>
#include <stdlib.h>

size_t *len;
size_t i;
uint8_t *ptr;
int found;

static uint8_t data[131072]; // 128KB of input data

void init_vars() {
    static size_t length = 131072;
    len = &length;
    ptr = data;
    found = 0;
    i = 0;

    // Initialize data with 0s, except place the pattern {255, 255} near the end to ensure loop runs most iterations
    for (size_t idx = 0; idx < length; ++idx) {
        data[idx] = 0;
    }
    data[length - 2] = 255;
    data[length - 1] = 255;
}