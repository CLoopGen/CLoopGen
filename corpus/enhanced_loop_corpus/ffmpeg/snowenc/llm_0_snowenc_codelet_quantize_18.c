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
    for (y = 0; y < h; y++) {
        int index = y * stride;
        for (x = 0; x < w; x++) {
            dst[x + index] = src[x + index];
        }
    }
}
