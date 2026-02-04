#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int buf_size;
int current_pos;
int startcode_found;
int i;

void init_vars() {
    buf_size = 64 * 1024 * 1024; // 64 MB buffer
    current_pos = 0;
    startcode_found = 0;
    i = 0;

    buf = (uint8_t*)malloc(buf_size);
    if (!buf) {
        exit(1);
    }

    // Initialize buffer with zeros except place the pattern near the end to ensure loop runs most of the way
    for (int j = 0; j < buf_size; j++) {
        buf[j] = 0;
    }

    // Place the target pattern at position allowing access to i+4: {0,0,1,182,x} within bounds
    if (buf_size >= 5) {
        int pos = buf_size - 5;
        buf[pos] = 0;
        buf[pos + 1] = 0;
        buf[pos + 2] = 1;
        buf[pos + 3] = 182;
        buf[pos + 4] = 0; // buf[i+4] & 64 == 0, so startcode_found becomes 1
    }
}