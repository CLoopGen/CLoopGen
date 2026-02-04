#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int size;
int i;
int ff_count;
uint8_t *buf;

void init_vars() {
    size = 1 << 20; // 1MB of data
    ff_count = 1000;
    buf = (uint8_t*)calloc(size + ff_count, sizeof(uint8_t));
    if (!buf) exit(1);

    for (int j = 0; j < size; j++) {
        buf[j] = (j % 256);
    }
    // Ensure that the last few values are 255 so ff_count decrement triggers
    for (int j = size - ff_count; j < size; j++) {
        buf[j] = 255;
    }

    i = size - 1;
}

// Reset globals if needed in future calls
void loop(); // declaration

__attribute__((constructor))
static void init() {
    init_vars();
}