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
    // Variant 2: Strided Memory Access with Reverse Traversal
    int total_elements = w * dst_step;
    int stride = dst_step;

    // Reverse the access order: process from last to first with fixed stride
    for (i = w - 1; i >= 0; i--) {
        int rev_i = w - 1 - i;  // reversed index
        int dst_offset = rev_i * dst_step;
        int src_offset = rev_i * src_step;
        int ref_offset = rev_i * ref_step;

        // Use same computation but on reversed data positions
        DWTELEM sum_ref = ref[ref_offset] + ref[ref_offset + ref_step];
        DWTELEM computed = (mul * sum_ref + add) >> shift;

        if (inverse) {
            dst[dst_offset] = src[src_offset] - computed;
        } else {
            dst[dst_offset] = src[src_offset] + computed;
        }
    }
}
