#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ScanTable {
    const uint8_t *scantable;
    uint8_t permutated[64];
    uint8_t raster_end[64];
} ScanTable;

extern uint8_t *permutation;
extern ScanTable *st;
extern  uint8_t *src_scantable;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (i = 0; i < 64; i += 2) {
        int j1 = src_scantable[i];
        st->permutated[i] = permutation[j1];
    }
    for (i = 1; i < 64; i += 2) {
        int j2 = src_scantable[i];
        st->permutated[i] = permutation[j2];
    }
}
