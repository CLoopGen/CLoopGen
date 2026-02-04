#include <stdint.h>
#include <stdlib.h>

typedef struct Node {
    int16_t sym;
    int16_t n0;
    uint32_t count;
    int16_t l;
    int16_t r;
} Node;

uint32_t *table;
Node nodes[512];
int i;

void init_vars() {
    const size_t table_size = 256;
    table = (uint32_t*)calloc(table_size, sizeof(uint32_t));
    if (!table) exit(1);

    for (size_t idx = 0; idx < table_size; idx++) {
        table[idx] = (uint32_t)(idx * 37 + 1); 
    }

    for (int idx = 0; idx < 512; idx++) {
        nodes[idx].sym = 0;
        nodes[idx].n0 = 0;
        nodes[idx].count = 0;
        nodes[idx].l = 0;
        nodes[idx].r = 0;
    }

    i = 0;
}