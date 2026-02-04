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
    // Variant 1: Consecutive memory access with row-major linear indexing and prefetching pattern
    int index = 0;
    for (y = 0; y < h; y++) {
        int base_src = y * stride;
        int base_dst = y * stride;
        for (x = 0; x < w; x++) {
            int i = src[base_src + x];
            if ((unsigned int)(i + thres1) > thres2) {
                if (i >= 0) {
                    i <<= (7 - 4 + 8);
                    i = (i + bias) / qmul;
                    dst[base_dst + x] = i;
                } else {
                    i = -i;
                    i <<= (7 - 4 + 8);
                    i = (i + bias) / qmul;
                    dst[base_dst + x] = -i;
                }
            } else {
                dst[base_dst + x] = 0;
            }
            index++;
        }
    }
}
