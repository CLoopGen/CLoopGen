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
    // Variant 2: Strided (Column-Major) Memory Access Pattern
    // Traverse the arrays column by column instead of row by row,
    // leading to strided access with step size equal to stride
    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            int idx = x + y * stride;
            int i = src[idx];
            if ((unsigned int)(i + thres1) > thres2) {
                if (i >= 0) {
                    i <<= (7 - 4 + 8);
                    i /= qmul;
                    dst[idx] = i;
                } else {
                    i = -i;
                    i <<= (7 - 4 + 8);
                    i /= qmul;
                    dst[idx] = -i;
                }
            } else
                dst[idx] = 0;
        }
    }
}
