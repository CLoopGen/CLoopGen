#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
    int16_t sym;
    int16_t n0;
    uint32_t count;
} Node;

uint8_t coeff_model[1 << 20];
uint8_t *map;
unsigned int size;
Node nodes[24];
Node *tmp;
int a;
int b;
int i;

void init_vars() {
    size = 1 << 20;
    map = aligned_alloc(32, sizeof(uint8_t) * 2 * size);
    tmp = aligned_alloc(32, sizeof(Node) * size);

    for (unsigned int j = 0; j < size; ++j) {
        coeff_model[j] = (uint8_t)(j % 256);
    }

    for (unsigned int j = 0; j < 2 * size; ++j) {
        map[j] = (uint8_t)((j / 2) % 24);
    }

    for (unsigned int j = 0; j < size; ++j) {
        tmp[j].count = (uint32_t)(j + 1);
    }

    for (int j = 0; j < 24; ++j) {
        nodes[j].sym = (int16_t)(j);
        nodes[j].n0 = (int16_t)(j);
        nodes[j].count = 0;
    }
}