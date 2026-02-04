#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ExtentPacket {
    double center;
    ssize_t index;
    ssize_t left;
    ssize_t right;
} ExtentPacket;

extern  short *extrema;
extern ExtentPacket *extents;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t *indices = (ssize_t*)malloc(256 * sizeof(ssize_t));
    for (ssize_t i = 0; i < 256; i++) {
        indices[i] = extents->index + i;
    }
    for (ssize_t i = 0; i < 256; i++) {
        ssize_t idx = indices[i];
        if (idx <= 255 && extrema[idx] > 0) {
            extents->index = idx;
            break;
        }
    }
    free(indices);
}
