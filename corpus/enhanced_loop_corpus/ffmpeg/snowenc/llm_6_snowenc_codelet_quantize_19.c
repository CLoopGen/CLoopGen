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
    for (y = 0; y < h; y++) {
        int base_idx = y * stride;
        for (x = 0; x < w; x++) {
            int idx = x + base_idx;
            int i = src[idx];
            int abs_i = (i >= 0) ? i : -i;
            int shifted = abs_i << (7 - 4 + 8);
            int scaled = shifted / qmul;
            int result = (i >= 0) ? scaled : -scaled;
            int threshold_check = (unsigned int)(i + thres1) > thres2;
            dst[idx] = threshold_check ? result : 0;
        }
    }
}
