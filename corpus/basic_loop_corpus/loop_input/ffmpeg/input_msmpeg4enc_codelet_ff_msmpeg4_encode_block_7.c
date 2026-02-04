#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
int last_index;
uint8_t *scantable;

void init_vars() {
    const int size = 64;
    block = (int16_t*)aligned_alloc(32, sizeof(int16_t) * size);
    scantable = (uint8_t*)aligned_alloc(32, sizeof(uint8_t) * size);

    for (int i = 0; i < size; i++) {
        block[i] = 0;
        scantable[i] = size - 1 - i;
    }

    block[scantable[0]] = 1;

    last_index = 63;
}

__attribute__((destructor))
void cleanup() {
    free(block);
    free(scantable);
}