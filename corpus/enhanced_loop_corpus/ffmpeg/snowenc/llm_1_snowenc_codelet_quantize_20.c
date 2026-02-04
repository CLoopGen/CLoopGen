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
    int total = w * h;
    for (int idx = 0; idx < total; idx++) {
        int y = idx / w;
        int x = idx % w;
        int i = src[x + y * stride];
        if ((unsigned int)(i + thres1) > thres2) {
            if (i >= 0) {
                i <<= (7 - 4 + 8);
                i = (i + bias) / qmul;
                dst[x + y * stride] = i;
            } else {
                i = -i;
                i <<= (7 - 4 + 8);
                i = (i + bias) / qmul;
                dst[x + y * stride] = -i;
            }
        } else {
            dst[x + y * stride] = 0;
        }
    }
}
