#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size = (1 << 20); // 1MB of data: 2^20 elements
uint16_t *top;
uint16_t *filtered_top;

void init_vars() {
    top = (uint16_t*)aligned_alloc(32, (size + 2) * sizeof(uint16_t));
    filtered_top = (uint16_t*)aligned_alloc(32, (size + 2) * sizeof(uint16_t));

    if (!top || !filtered_top) {
        exit(1);
    }

    for (int idx = 0; idx < size + 2; idx++) {
        top[idx] = (uint16_t)(idx & 0xFFFF);
    }

    for (int idx = 0; idx < size + 2; idx++) {
        filtered_top[idx] = 0;
    }
}

void loop(); // forward declaration

__attribute__((constructor))
static void constructor() {
    init_vars();
}