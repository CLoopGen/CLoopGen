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
    DWTELEM temp;
    for (i = 0; i < w; i++) {
        temp = ref[i * ref_step] + ref[(i + 1) * ref_step];
        dst[i * dst_step] = src[i * src_step] + ((inverse ? -((mul * temp + add) >> shift) : ((mul * temp + add) >> shift)));
    }
}
