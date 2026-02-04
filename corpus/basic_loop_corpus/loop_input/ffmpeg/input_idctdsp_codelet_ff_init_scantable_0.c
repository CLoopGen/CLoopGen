#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ScanTable {
    const uint8_t *scantable;
    uint8_t permutated[64];
    uint8_t raster_end[64];
} ScanTable;

uint8_t *permutation;
ScanTable *st;
uint8_t *src_scantable;
int i;

void init_vars() {
    permutation = (uint8_t *)malloc(256 * sizeof(uint8_t));
    for (int idx = 0; idx < 256; idx++) {
        permutation[idx] = (uint8_t)(idx * idx + 3 * idx + 1) & 0xFF;
    }

    st = (ScanTable *)malloc(sizeof(ScanTable));
    st->scantable = NULL;

    src_scantable = (uint8_t *)malloc(64 * sizeof(uint8_t));
    for (int idx = 0; idx < 64; idx++) {
        src_scantable[idx] = (uint8_t)(63 - idx);
    }

    i = 0;
}