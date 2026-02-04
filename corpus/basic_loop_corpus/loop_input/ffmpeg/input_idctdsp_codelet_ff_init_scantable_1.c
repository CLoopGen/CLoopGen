#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ScanTable {
    const uint8_t *scantable;
    uint8_t permutated[64];
    uint8_t raster_end[64];
} ScanTable;

static uint8_t global_scantable[64];
ScanTable *st;
int i;
int end;

void init_vars() {
    st = (ScanTable*)malloc(sizeof(ScanTable));
    if (!st) exit(1);
    
    st->scantable = global_scantable;
    
    for (int idx = 0; idx < 64; idx++) {
        st->permutated[idx] = rand() % 64;
        st->raster_end[idx] = 0;
        global_scantable[idx] = idx;
    }
    
    i = 0;
    end = 0;
}