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
extern  uint8_t *pretab;
extern int len;
extern int i;
extern int j;
extern int v0;
extern int shift;
extern int gain;
extern int16_t *exp_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with unrolled stride-2 pattern
    // Instead of processing one element at a time, we process two consecutively to improve spatial locality.
    // We assume that g->long_end is even; if not, the original loop behavior would require handling remainder.
    int limit = g->long_end & ~1;  // Round down to even number
    for (i = 0; i < limit; i += 2) {
        int v0_0 = gain - ((g->scale_factors[i] + pretab[i]) << shift) + 400;
        int v0_1 = gain - ((g->scale_factors[i+1] + pretab[i+1]) << shift) + 400;
        int len0 = bstab[i];
        int len1 = bstab[i+1];

        for (j = len0; j > 0; j--)
            *exp_ptr++ = v0_0;
        for (j = len1; j > 0; j--)
            *exp_ptr++ = v0_1;
    }
    // Handle leftover if g->long_end is odd
    if ((g->long_end & 1) && i < g->long_end) {
        v0 = gain - ((g->scale_factors[i] + pretab[i]) << shift) + 400;
        len = bstab[i];
        for (j = len; j > 0; j--)
            *exp_ptr++ = v0;
    }
}
