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
for (i = 0; i < 64; i++) {
    for (int k = 0; k <= i; k++) {
        int j = st->permutated[k];
        if (j > end)
            end = j;
        st->raster_end[k] = end;
    }
}
}
