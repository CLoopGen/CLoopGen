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
    double threshold = 0.5;
    for (; extents->index <= 127; extents->index++) {
        extents->center += (double)extrema[extents->index] * threshold;
        if (extrema[extents->index] > 0 && extents->center > 10.0) {
            break;
        }
    }
}
