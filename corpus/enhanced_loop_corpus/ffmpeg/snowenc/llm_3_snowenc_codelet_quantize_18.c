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
extern int x;
extern int y;
extern IDWTELEM *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased step size (block-wise traversal)
    // Simulate a strided access pattern by processing every second element first, then filling in
    int step = 2;
    int offset;

    for (offset = 0; offset < step; offset++) {
        for (y = 0; y < h; y++)
            for (x = offset; x < w; x += step)
                dst[x + y * stride] = src[x + y * stride];
    }
}
