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
    // Variant 1: Increased computational intensity with unrolled loop (tripled arithmetic workload per iteration)
    // Trip count reduced by factor of 2 for higher per-iteration cost, w assumed to be even
    int limit = w / 2;
    for (i = 0; i < limit; i++) {
        int idx1 = i * 2 * dst_step;
        int idx2 = (i * 2 + 1) * dst_step;
        int src_idx1 = i * 2 * src_step;
        int src_idx2 = (i * 2 + 1) * src_step;
        int ref_idx1 = i * 2 * ref_step;
        int ref_idx2 = (i * 2 + 1) * ref_step;

        // First element: original computation plus extra weighted combination
        DWTELEM base1 = (inverse) ? 
            (src[src_idx1]) + (((mul * (ref[ref_idx1] + ref[(i*2 + 1) * ref_step]) + add) + 4 * (src[src_idx1])) >> shift) :
            -((-16 * (src[src_idx1]) + (mul * (ref[ref_idx1] + ref[(i*2 + 1) * ref_step]) + add) + add / 4 + 1 + (5 << 25)) / 20 - (1 << 23));

        // Second element with auxiliary computation: add a secondary blending term
        DWTELEM base2 = (inverse) ? 
            (src[src_idx2]) + (((mul * (ref[(i*2+1)*ref_step] + ref[(i*2+2)*ref_step]) + add) + 4 * (src[src_idx2])) >> shift) :
            -((-16 * (src[src_idx2]) + (mul * (ref[(i*2+1)*ref_step] + ref[(i*2+2)*ref_step]) + add) + add / 4 + 1 + (5 << 25)) / 20 - (1 << 23));

        // Additional complexity: blend results conditionally based on sum magnitude
        DWTELEM mix_factor = (base1 + base2) & ((1 << (shift - 2)) - 1);
        base1 += (mix_factor * 3) >> (shift - 4);
        base2 -= (mix_factor * 2) >> (shift - 5);

        dst[idx1] = base1;
        dst[idx2] = base2;
    }
}
