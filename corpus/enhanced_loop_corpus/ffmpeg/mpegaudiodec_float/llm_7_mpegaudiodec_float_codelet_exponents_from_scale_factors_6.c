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
    int local_k = k; // Break potential loop-carried WAW/WAR on global k
    for (i = g->short_start; i < 13; i++) {
        len = bstab[i];
        for (l = 0; l < 3; l++) {
            // Introduce artificial RAW dependency: v0 used to compute next shift effect
            int adjusted_shift = shift + ((l > 0) ? (v0 >> 8) & 0x3 : 0);
            v0 = gains[l] - (g->scale_factors[local_k++] << adjusted_shift) + 400;
            // Unroll inner loop once to create more data reuse and change access pattern
            if (len >= 2) {
                int rem = len % 2;
                for (j = 0; j < len / 2; j++) {
                    exp_ptr[0] = v0;
                    exp_ptr[1] = v0;
                    exp_ptr += 2;
                }
                if (rem) *exp_ptr++ = v0;
            } else {
                for (j = len; j > 0; j--)
                    *exp_ptr++ = v0;
            }
        }
    }
    k = local_k; // Update global k only once at end, reducing WAW pressure
}
