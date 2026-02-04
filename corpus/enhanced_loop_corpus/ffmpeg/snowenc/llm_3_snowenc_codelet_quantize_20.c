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
    // Variant 2: Strided column-major memory access to change spatial locality
    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            int offset = x + y * stride;
            int i = src[offset];
            if ((unsigned int)(i + thres1) > thres2) {
                if (i >= 0) {
                    i <<= (7 - 4 + 8);
                    i = (i + bias) / qmul;
                    dst[offset] = i;
                } else {
                    i = -i;
                    i <<= (7 - 4 + 8);
                    i = (i + bias) / qmul;
                    dst[offset] = -i;
                }
            } else {
                dst[offset] = 0;
            }
        }
    }
}
