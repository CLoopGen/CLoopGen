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
    int temp_end = end;
    for (i = 0; i < 64; i++) {
        int j = st->permutated[i];
        temp_end = (j > temp_end) ? j : temp_end;
        st->raster_end[i] = temp_end;
    }
    end = temp_end;
}
