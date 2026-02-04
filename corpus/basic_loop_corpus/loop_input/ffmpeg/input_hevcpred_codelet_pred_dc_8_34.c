#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size = 16777216; // 16M elements, ~0.01 sec on modern CPU
uint8_t *top;
uint8_t *left;
int dc = 0;

void init_vars() {
    top = aligned_alloc(32, size * sizeof(uint8_t));
    left = aligned_alloc(32, size * sizeof(uint8_t));

    if (!top || !left) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < size; idx++) {
        top[idx] = rand() & 0xFF;
        left[idx] = rand() & 0xFF;
    }
}