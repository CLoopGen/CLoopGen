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
int idx;
DWTELEM src_val;
for (i = 0; i < w; i++) {
    idx = i * dst_step;
    src_val = src[i * src_step];
    if (!inverse) continue;
    dst[idx] = src_val + ((mul * (ref[i * ref_step] + ref[(i + 1) * ref_step]) + add) + 4 * src_val >> shift);
}
}
