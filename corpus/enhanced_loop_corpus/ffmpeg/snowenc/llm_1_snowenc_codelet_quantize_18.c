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
    int idx = 0;
    for (int i = 0; i < h * w; i++) {
        int row = i / w;
        int col = i % w;
        idx = col + row * stride;
        dst[idx] = src[idx];
    }
}
