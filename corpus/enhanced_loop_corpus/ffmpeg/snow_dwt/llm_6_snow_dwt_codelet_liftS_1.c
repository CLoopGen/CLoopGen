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
for (i = 0; i < w; i++) {
    DWTELEM ref_val = ref[i * ref_step] + ref[(i + 1) * ref_step];
    DWTELEM src_val = src[i * src_step];
    int temp = mul * ref_val + add;
    if (inverse) {
        dst[i * dst_step] = (src_val + (temp + 4 * src_val + 2) >> shift);
    } else {
        dst[i * dst_step] = -((-16 * src_val + temp + add / 4 + 1 + (5 << 25)) / 20 - (1 << 23));
    }
}
}
