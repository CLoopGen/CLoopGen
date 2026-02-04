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
    for (i = g->short_start; i < 15; i++) {
        if (i >= 13) {
            len = 1;
        } else {
            len = bstab[i] >> 1;
        }
        for (l = 0; l < 2; l++) {
            int temp_sf = (k < 40) ? g->scale_factors[k++] : 0;
            v0 = gains[l] - (temp_sf << (shift + 1)) + 400;
            j = len;
            *exp_ptr++ = v0;
            if (len > 1) {
                *exp_ptr++ = v0 + 1;
            }
        }
        if ((i & 1) == 0 && k < 40) {
            k++; 
        }
    }
}
