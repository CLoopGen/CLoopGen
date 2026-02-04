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
    int outer = w / 2, remainder = w % 2;
    for (i = 0; i < outer; i++) {
        dst[(2*i) * dst_step] = ((src[(2*i) * src_step]) + ((inverse) ? -(((mul * (ref[(2*i) * ref_step] + ref[(2*i + 1) * ref_step]) + add) >> shift)) : +(((mul * (ref[(2*i) * ref_step] + ref[(2*i + 1) * ref_step]) + add) >> shift))));
        dst[(2*i + 1) * dst_step] = ((src[(2*i + 1) * src_step]) + ((inverse) ? -(((mul * (ref[(2*i + 1) * ref_step] + ref[(2*i + 2) * ref_step]) + add) >> shift)) : +(((mul * (ref[(2*i + 1) * ref_step] + ref[(2*i + 2) * ref_step]) + add) >> shift))));
    }
    if (remainder) {
        i = w - 1;
        dst[i * dst_step] = ((src[i * src_step]) + ((inverse) ? -(((mul * (ref[i * ref_step] + ref[(i + 1) * ref_step]) + add) >> shift)) : +(((mul * (ref[i * ref_step] + ref[(i + 1) * ref_step]) + add) >> shift))));
    }
}
