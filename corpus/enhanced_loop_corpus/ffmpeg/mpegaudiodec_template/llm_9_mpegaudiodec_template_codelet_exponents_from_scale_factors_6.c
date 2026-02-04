#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct GranuleDef {
    uint8_t scfsi;
    int part2_3_length;
    int big_values;
    int global_gain;
    int scalefac_compress;
    uint8_t block_type;
    uint8_t switch_point;
    int table_select[3];
    int subblock_gain[3];
    uint8_t scalefac_scale;
    uint8_t count1table_select;
    int region_size[3];
    int preflag;
    int short_start;
    int long_end;
    uint8_t scale_factors[40];
    int sb_hybrid[576] __attribute__((aligned(16)));
} GranuleDef;

extern GranuleDef *g;
extern  uint8_t *bstab;
extern int len;
extern int i;
extern int j;
extern int k;
extern int l;
extern int v0;
extern int shift;
extern int gains[3];
extern int16_t *exp_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity by flattening nested loops and reducing trip counts.
    // Merged two levels of looping into one using index mapping, reduced iterations.
    int total_iters = (13 - g->short_start) * 2;  // Reduced from 3 to 2 inner iterations
    k = 0; // Reset k if needed, though external state assumed
    for (i = 0; i < total_iters; i++) {
        int granule_idx = g->short_start + (i / 2);
        int l = i % 2;
        len = bstab[granule_idx];
        v0 = gains[l] - (g->scale_factors[k++] << shift) + 400;
        // Eliminated inner loop over 'j' by writing only once per segment (downsampling effect)
        if (len > 0) {
            *exp_ptr++ = v0;
        }
    }
}
