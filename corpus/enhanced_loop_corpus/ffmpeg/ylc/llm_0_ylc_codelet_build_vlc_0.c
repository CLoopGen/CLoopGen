#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Node {
    int16_t sym;
    int16_t n0;
    uint32_t count;
    int16_t l;
    int16_t r;
} Node;

extern  uint32_t *table;
extern Node nodes[512];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; ++j) {
        for (i = 0; i < 128; i++) {
            int idx = (j == 0) ? i : i + 128;
            nodes[idx].count = table[idx];
            nodes[idx].sym = idx;
            nodes[idx].n0 = -2;
            nodes[idx].l = idx;
            nodes[idx].r = idx;
        }
    }
}
