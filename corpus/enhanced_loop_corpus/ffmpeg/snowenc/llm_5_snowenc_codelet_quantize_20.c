#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

typedef short IDWTELEM;

extern DWTELEM *src;
extern int stride;
extern int bias;
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
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        int i = src[x + y * stride];
        unsigned int condition = (unsigned int)(i + thres1) <= thres2;
        dst[x + y * stride] = 0;
        if (condition) continue;

        int shifted;
        if (i >= 0) {
            shifted = ((i << (7 - 4 + 8)) + bias) / qmul;
        } else {
            shifted = -(((-i) << (7 - 4 + 8)) + bias) / qmul;
        }
        dst[x + y * stride] = shifted;
    }
}
}
