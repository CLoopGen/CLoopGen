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
    // Variant 1: Change access pattern to consecutive memory writes by precomputing values in a local buffer and copying in bulk
    int temp_buffer[39]; // Max possible: 3 * 13 = 39 elements, assuming worst-case bstab[i] = 1
    for (i = g->short_start; i < 13; i++) {
        len = bstab[i];
        int buf_idx = 0;
        for (l = 0; l < 3; l++) {
            v0 = gains[l] - (g->scale_factors[k++] << shift) + 400;
            for (j = len; j > 0; j--) {
                temp_buffer[buf_idx++] = v0;
            }
        }
        // Copy consecutive block to exp_ptr
        for (j = 0; j < buf_idx; j++) {
            *exp_ptr++ = temp_buffer[j];
        }
    }
}
