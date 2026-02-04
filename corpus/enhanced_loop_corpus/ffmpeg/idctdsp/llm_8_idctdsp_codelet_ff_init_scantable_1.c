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



void loop() {
    for (i = 0; i < 32; i += 2) {
        int j1 = st->permutated[i];
        int j2 = st->permutated[i + 1];
        if (j1 > end)
            end = j1;
        if (j2 > end)
            end = j2;
        st->raster_end[i] = end;
        st->raster_end[i + 1] = end;
    }
}
