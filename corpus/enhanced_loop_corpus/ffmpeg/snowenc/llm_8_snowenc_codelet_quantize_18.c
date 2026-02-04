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
    int i, j;
    for (i = 0; i < h; i += 2) {
        for (j = 0; j < w; j += 2) {
            int idx = j + i * stride;
            dst[idx] = src[idx];
            if (j + 1 < w) dst[idx + 1] = src[idx + 1];
            if (i + 1 < h) dst[idx + stride] = src[idx + stride];
            if (i + 1 < h && j + 1 < w) dst[idx + stride + 1] = src[idx + stride + 1];
        }
    }
}
