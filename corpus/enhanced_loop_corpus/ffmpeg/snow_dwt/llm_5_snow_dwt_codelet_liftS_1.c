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
DWTELEM combined_ref, temp_result;
for (i = 0; i < w; i++) {
    combined_ref = ref[i * ref_step] + ref[(i + 1) * ref_step];
    if (inverse == 1) {
        dst[i * dst_step] = src[i * src_step] + ((mul * combined_ref + add) + 4 * src[i * src_step] >> shift);
    } else {
        temp_result = (-16 * src[i * src_step] + mul * combined_ref + add + add / 4 + 1 + (5 << 25)) / 20 - (1 << 23);
        dst[i * dst_step] = -temp_result;
    }
}
}
