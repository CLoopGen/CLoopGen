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
    ssize_t step = 2;
    for (; extents->index <= 255; extents->index += step) {
        if (extrema[extents->index] < 0)
            break;
        if (extents->index + 1 <= 255 && extrema[extents->index + 1] >= 0)
            extents->center += extrema[extents->index + 1];
    }
}
