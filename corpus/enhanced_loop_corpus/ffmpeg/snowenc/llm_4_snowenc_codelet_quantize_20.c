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
        unsigned int threshold_check = (unsigned int)(i + thres1) > thres2;
        if (!threshold_check) {
            dst[x + y * stride] = 0;
            continue;
        }
        int abs_i = i >= 0 ? i : -i;
        abs_i <<= (7 - 4 + 8);
        abs_i = (abs_i + bias) / qmul;
        dst[x + y * stride] = i >= 0 ? abs_i : -abs_i;
    }
}
}
