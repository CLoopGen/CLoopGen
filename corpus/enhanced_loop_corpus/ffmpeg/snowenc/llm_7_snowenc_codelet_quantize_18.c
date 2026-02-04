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
    for (int idx = 0; idx < h * w; idx++) {
        int y = idx / w;
        int x = idx % w;
        // Introduce artificial RAW and WAW dependency with a temporary accumulator
        IDWTELEM temp_val = (IDWTELEM)src[x + y * stride];
        dst[x + y * stride] = temp_val; // WAW: write-after-write on dst, RAW: read-after-write on temp_val
    }
}
