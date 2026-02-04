#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int block_w;
int x;
int end_x;
uint8_t *bufp;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB for ~0.01 sec runtime estimate
    bufp = (uint8_t*)malloc(data_size);
    if (!bufp) {
        exit(1);
    }

    block_w = data_size - 1;
    end_x = 1024; // Ensure end_x < block_w and valid access at end_x - 1

    // Initialize bufp[end_x - 1] to avoid undefined value
    bufp[end_x - 1] = 42;

    // Ensure rest of buffer is accessible; no need to zero entire buffer
}