#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int buf_size;
int i;

static uint8_t *internal_buf;

void init_vars() {
    buf_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    internal_buf = (uint8_t*)calloc(buf_size, sizeof(uint8_t));
    if (!internal_buf) {
        exit(1);
    }
    buf = internal_buf;

    // Ensure safe access for buf[i-1] and buf[i+1] by avoiding edges
    // Initialize pattern so that the loop runs a significant portion before breaking
    for (int j = 1; j < buf_size - 1; j += 2) {
        if (j % 10000 == 0) { // Introduce rare condition to trigger break
            buf[j] = 119;
            buf[j - 1] = 11;
            buf[j + 1] = 11 ^ (119 ^ 11); // Satisfy second XOR condition
            break;
        } else {
            buf[j] = 0;
        }
    }
}