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



void loop(){
    for (i = 0; i < g->long_end; i++) {
        v0 = gain - ((g->scale_factors[i] + pretab[i]) << shift) + 400;
        len = bstab[i];
        if (len > 0) {
            j = len;
            for (j = len; j > 0; j--) {
                *exp_ptr++ = v0;
            }
        }
    }
}
