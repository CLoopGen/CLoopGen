#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int buf_size;
int vop_found;
int i;
uint32_t state;

void init_vars() {
    buf_size = 16777216; // 16 MB to target ~0.01 sec runtime
    buf = (uint8_t *)malloc(buf_size);
    if (!buf) {
        exit(1);
    }
    for (int j = 0; j < buf_size; j++) {
        buf[j] = rand() & 0xFF;
    }
    // Ensure that the pattern 438 (0x01B6) does not appear early, but may appear at end
    // 438 = 0b0000000110110110, so we need sequence: 0x01 0xB6
    // Insert it near the end to allow loop to run long enough
    if (buf_size >= 2) {
        buf[buf_size - 2] = 0x01;
        buf[buf_size - 1] = 0xB6;
    }

    vop_found = 0;
    i = 0;
    state = 0;
}