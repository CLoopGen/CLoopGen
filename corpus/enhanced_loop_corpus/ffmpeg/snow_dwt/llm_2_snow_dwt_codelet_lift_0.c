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
    // Variant 1: Consecutive Memory Access (unrolled by 2 with linear indexing)
    int idx = 0;
    int dst_idx = 0;
    int src_idx = 0;
    int ref_idx = 0;

    for (i = 0; i < w - 1; i += 2) {
        // Process two elements at once using consecutive access pattern
        DWTELEM ref_val1 = ref[ref_idx];
        DWTELEM ref_val2 = ref[ref_idx + ref_step];
        DWTELEM ref_val3 = ref[ref_idx + ref_step * 2];

        dst[dst_idx] = (src[src_idx] + ((inverse) ? 
            -(((mul * (ref_val1 + ref_val2) + add) >> shift)) : 
               (((mul * (ref_val1 + ref_val2) + add) >> shift))));

        dst[dst_idx + dst_step] = (src[src_idx + src_step] + ((inverse) ? 
            -(((mul * (ref_val2 + ref_val3) + add) >> shift)) : 
               (((mul * (ref_val2 + ref_val3) + add) >> shift))));

        idx += 2;
        dst_idx += dst_step * 2;
        src_idx += src_step * 2;
        ref_idx += ref_step * 2;
    }

    // Handle remaining element if w is odd
    if (i < w) {
        dst[dst_idx] = (src[src_idx] + ((inverse) ? 
            -(((mul * (ref[ref_idx] + ref[ref_idx + ref_step]) + add) >> shift)) : 
               (((mul * (ref[ref_idx] + ref[ref_idx + ref_step]) + add) >> shift))));
    }
}
