#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size = 65536; // Approximately 128KB of data (65536 * 2 bytes * 2 arrays), ensures ~0.01s runtime
uint16_t *top;
uint16_t *filtered_top;

void init_vars() {
    top = aligned_alloc(32, (size * 2) * sizeof(uint16_t));
    filtered_top = aligned_alloc(32, (size * 2) * sizeof(uint16_t));

    for (int idx = 0; idx < size * 2; idx++) {
        top[idx] = rand() & 0xFFFF;
        filtered_top[idx] = 0;
    }

    i = 2 * size - 2;
}