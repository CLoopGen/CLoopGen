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
    // Variant 1: Consecutive memory access by transposing the iteration order
    // Access pattern changed to iterate over contiguous blocks in memory where possible
    for (x = 0; x < w; x++)
        for (y = 0; y < h; y++)
            dst[x + y * stride] = src[x + y * stride];
}
