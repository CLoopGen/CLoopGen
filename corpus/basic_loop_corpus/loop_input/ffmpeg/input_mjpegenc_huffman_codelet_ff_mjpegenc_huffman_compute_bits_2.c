#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HuffTable {
    int code;
    int length;
} HuffTable;

HuffTable *distincts;
int i;
int j;
int nbits[257];

void init_vars() {
    const size_t distincts_size = 1 << 20;
    distincts = (HuffTable *)calloc(distincts_size, sizeof(HuffTable));
    if (!distincts) exit(1);

    for (int idx = 0; idx < 256; idx++) {
        nbits[idx] = (rand() % 16) + 1;
    }
    nbits[256] = 0;

    i = 0;
    j = 0;
}