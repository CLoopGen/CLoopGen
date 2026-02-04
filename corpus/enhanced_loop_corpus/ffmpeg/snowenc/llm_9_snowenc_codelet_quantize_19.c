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
int shift = (7 - 4 + 8);
int scaled_qmul = qmul << shift;
for (y = 0; y < h; y++) {
    int offset = y * stride;
    for (x = 0; x < w; x++) {
        int index = x + offset;
        int i = src[index];
        unsigned int threshold_check = (unsigned int)(i + thres1);
        if (threshold_check > thres2) {
            int abs_i = (i >= 0) ? i : -i;
            int shifted = abs_i << shift;
            int quotient = shifted / qmul;
            dst[index] = (i >= 0) ? quotient : -quotient;
        } else {
            dst[index] = 0;
        }
    }
}
}
