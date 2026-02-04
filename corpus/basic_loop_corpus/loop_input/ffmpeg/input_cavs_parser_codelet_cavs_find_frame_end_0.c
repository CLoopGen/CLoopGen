#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int buf_size;
int pic_found;
int i;
uint32_t state;

void init_vars() {
    buf_size = 64 * 1024 * 1024; // 64 MB buffer for ~0.01 sec runtime on modern CPU
    buf = (uint8_t *)malloc(buf_size);
    if (!buf) {
        exit(1);
    }
    for (int j = 0; j < buf_size; j++) {
        buf[j] = rand() & 0xFF;
    }
    // Ensure no early termination by avoiding patterns 435 and 438 in state
    // We'll set initial bytes to safe values and control state manually if needed
    // But allow possibility of match near the end to test logic
    // Force a match at the end to ensure coverage
    buf[buf_size - 4] = (435 >> 8) & 0xFF;
    buf[buf_size - 3] = 435 & 0xFF;
    buf[buf_size - 2] = 0;
    buf[buf_size - 1] = 0;

    pic_found = 0;
    i = 0;
    state = 0;
}