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
    float sb_hybrid[576] __attribute__((aligned(16)));
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
    // Variant 2: Use strided array access by reordering the loop nests and accessing scale_factors with a fixed stride pattern
    // Simulate indirect/scattered read from scale_factors with controlled increment
    int base_k = k;
    for (i = g->short_start; i < 13; i++) {
        len = bstab[i];
        for (j = len; j > 0; j--) {
            for (l = 0; l < 3; l++) {
                // Strided access: compute k indirectly via i and l
                int idx = base_k + (i - g->short_start) * 3 + l;
                v0 = gains[l] - (g->scale_factors[idx] << shift) + 400;
                *exp_ptr++ = v0;
            }
        }
    }
    // Update k to reflect total number of scale_factors consumed
    k = base_k + (13 - g->short_start) * 3;
}
