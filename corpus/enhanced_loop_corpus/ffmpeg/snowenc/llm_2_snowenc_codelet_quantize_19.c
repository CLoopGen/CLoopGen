#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

typedef short IDWTELEM;

extern DWTELEM *src;
extern int stride;
extern  int w;
extern  int h;
extern  int qmul;
extern int x;
extern int y;
extern int thres1;
extern int thres2;
extern IDWTELEM *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern using row-major linear indexing
    // Instead of recalculating x + y*stride each time, we step consecutively through memory
    // assuming that the data is accessed in a more cache-friendly sequential manner.
    int offset = 0;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            int i = src[offset];
            if ((unsigned int)(i + thres1) > thres2) {
                if (i >= 0) {
                    i <<= (7 - 4 + 8);
                    i /= qmul;
                    dst[offset] = i;
                } else {
                    i = -i;
                    i <<= (7 - 4 + 8);
                    i /= qmul;
                    dst[offset] = -i;
                }
            } else
                dst[offset] = 0;
            offset++;
        }
        // Skip any padding beyond width to maintain correct row alignment
        offset += (stride - w);
    }
}
