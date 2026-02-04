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
    for (x = 0; x < w; x += 2) {
        int i1 = src[x + y * stride];
        int i2 = (x + 1 < w) ? src[x + 1 + y * stride] : 0;
        int val1, val2;

        if ((unsigned int)(i1 + thres1) > thres2) {
            if (i1 >= 0) {
                val1 = (i1 << (7 - 4 + 8)) / qmul;
            } else {
                val1 = -(((-i1) << (7 - 4 + 8)) / qmul);
            }
        } else {
            val1 = 0;
        }

        if (x + 1 < w) {
            if ((unsigned int)(i2 + thres1) > thres2) {
                if (i2 >= 0) {
                    val2 = (i2 << (7 - 4 + 8)) / qmul;
                } else {
                    val2 = -(((-i2) << (7 - 4 + 8)) / qmul);
                }
            } else {
                val2 = 0;
            }
            dst[x + 1 + y * stride] = val2;
        }

        dst[x + y * stride] = val1;
    }
}
}
