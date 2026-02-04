#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

extern DWTELEM *dst;
extern DWTELEM *src;
extern DWTELEM *ref;
extern int dst_step;
extern int src_step;
extern int ref_step;
extern int mul;
extern int add;
extern int shift;
extern int inverse;
extern  int w;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    DWTELEM acc = 0;
    for (i = 0; i < w; i++) {
        DWTELEM ref_val = ref[i * ref_step] + ref[(i + 1) * ref_step];
        DWTELEM delta = (mul * ref_val + add) >> shift;
        if (inverse) delta = -delta;
        acc += delta; // Introduce loop-carried dependence (WAW and RAW on acc)
        dst[i * dst_step] = src[i * src_step] + acc;
    }
}
