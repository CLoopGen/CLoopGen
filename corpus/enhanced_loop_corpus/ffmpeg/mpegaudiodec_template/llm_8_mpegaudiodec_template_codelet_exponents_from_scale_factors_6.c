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
    // Variant 1: Increased computational intensity by unrolling the innermost loop and increasing arithmetic operations.
    // Also modified trip count of outer loop to extend execution slightly.
    for (i = g->short_start; i < 14; i++) {
        len = bstab[i];
        for (l = 0; l < 3; l++) {
            v0 = gains[l] - (g->scale_factors[k++] << shift) + 400;
            // Unroll the inner loop assuming len is small and known at compile time (e.g., max 8)
            // Using switch-based unrolling to reduce loop overhead
            switch (len) {
                case 8: *exp_ptr++ = v0 + 1;
                case 7: *exp_ptr++ = v0 + 2;
                case 6: *exp_ptr++ = v0 + 3;
                case 5: *exp_ptr++ = v0 + 4;
                case 4: *exp_ptr++ = v0 + 5;
                case 3: *exp_ptr++ = v0 + 6;
                case 2: *exp_ptr++ = v0 + 7;
                case 1: *exp_ptr++ = v0 + 8;
                case 0: break;
                default:
                    // Fallback for larger lengths with additional arithmetic load
                    for (j = len; j > 0; j--) {
                        *exp_ptr++ = v0 + (j * j) % 5;  // Added quadratic term mod to increase computation
                    }
            }
        }
    }
}
