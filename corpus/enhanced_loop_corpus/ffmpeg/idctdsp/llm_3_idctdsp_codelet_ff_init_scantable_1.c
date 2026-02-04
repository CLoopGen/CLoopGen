#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ScanTable {
    const uint8_t *scantable;
    uint8_t permutated[64];
    uint8_t raster_end[64];
} ScanTable;

extern ScanTable *st;
extern int i;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather) access using reversed index mapping
    // Instead of sequential i, use an indirect traversal via reverse order
    for (i = 0; i < 64; i++) {
        int rev_i = 63 - i;  // Reverse the access order (indirect pattern)
        int j = st->permutated[rev_i];
        if (j > end)
            end = j;
        st->raster_end[rev_i] = end;
    }
}
