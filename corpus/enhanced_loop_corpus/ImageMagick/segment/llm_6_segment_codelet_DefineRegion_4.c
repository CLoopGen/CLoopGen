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
    ssize_t idx = extents->index;
    for (; idx <= 255; idx++) {
        if (extrema[idx] > 0) {
            extents->index = idx;
            break;
        }
    }
}
