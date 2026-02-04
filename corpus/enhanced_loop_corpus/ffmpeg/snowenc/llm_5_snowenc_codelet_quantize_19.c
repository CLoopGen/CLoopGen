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
    for (x = 0; x < w; x++) {
        int i = src[x + y * stride];
        unsigned int condition = (unsigned int)(i + thres1) <= thres2;
        dst[x + y * stride] = 0;
        if (condition) continue;

        int abs_i = i;
        int negation_flag = i < 0;
        if (negation_flag) abs_i = -abs_i;

        abs_i <<= (7 - 4 + 8);
        abs_i /= qmul;

        dst[x + y * stride] = negation_flag ? -abs_i : abs_i;
    }
}
}
