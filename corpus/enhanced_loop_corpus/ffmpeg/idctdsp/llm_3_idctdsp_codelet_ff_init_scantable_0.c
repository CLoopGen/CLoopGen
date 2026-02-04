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
    // Variant 2: Consecutive forward access with local blocking (loop unrolling by 4)
    for (i = 0; i < 64; i += 4) {
        int j0 = src_scantable[i];
        int j1 = src_scantable[i + 1];
        int j2 = src_scantable[i + 2];
        int j3 = src_scantable[i + 3];
        
        st->permutated[i]     = permutation[j0];
        st->permutated[i + 1] = permutation[j1];
        st->permutated[i + 2] = permutation[j2];
        st->permutated[i + 3] = permutation[j3];
    }
}
