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
    uint8_t temp[64];
    for (i = 0; i < 64; i++) {
        int j = src_scantable[i];
        temp[i] = permutation[j];
    }
    for (i = 0; i < 64; i++) {
        st->permutated[i] = temp[i];
    }
}
