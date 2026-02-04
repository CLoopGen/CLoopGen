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
    for (i = 0; i < 64; i++) {
        int j = src_scantable[i];
        uint8_t val = permutation[j];
        if (val != 0) {
            st->permutated[i] = val;
        } else {
            st->permutated[i] = src_scantable[i];
        }
    }
}
