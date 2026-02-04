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
    double prev_center = extents->center;
    for (; extents->index <= 255; extents->index++) {
        if (extrema[extents->index] > 0) {
            extents->center = prev_center + extents->index;
            prev_center = extents->center;
            break;
        }
    }
}
