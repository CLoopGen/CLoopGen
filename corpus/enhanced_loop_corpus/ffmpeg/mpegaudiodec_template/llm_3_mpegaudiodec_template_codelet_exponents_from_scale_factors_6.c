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
    // Variant 2: Memory Access Pattern Modification - Strided access with reversed outer loop
    int stride = 16; // Example stride to simulate non-unit access pattern
    int16_t *base_ptr = exp_ptr;

    // Reverse the iteration order of the outer loop for different memory traversal
    for (i = 12; i >= g->short_start; i--) {
        len = bstab[i];
        for (l = 0; l < 3; l++) {
            v0 = gains[l] - (g->scale_factors[k++] << shift) + 400;
            // Write with fixed stride instead of consecutive locations
            for (j = 0; j < len; j++) {
                base_ptr[stride * j] = v0;
            }
            base_ptr += len; // Move base forward after strided writes
        }
    }
}
