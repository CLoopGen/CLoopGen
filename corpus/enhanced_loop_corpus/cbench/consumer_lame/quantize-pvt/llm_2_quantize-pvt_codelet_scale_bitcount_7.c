#include <stdio.h>

#include <inttypes.h>

typedef struct {
    unsigned int part2_3_length;
    unsigned int big_values;
    unsigned int count1;
    unsigned int global_gain;
    unsigned int scalefac_compress;
    unsigned int window_switching_flag;
    unsigned int block_type;
    unsigned int mixed_block_flag;
    unsigned int table_select[3];
    int subblock_gain[3];
    unsigned int region0_count;
    unsigned int region1_count;
    unsigned int preflag;
    unsigned int scalefac_scale;
    unsigned int count1table_select;
    unsigned int part2_length;
    unsigned int sfb_lmax;
    unsigned int sfb_smax;
    unsigned int count1bits;
    unsigned int *sfb_partition_table;
    unsigned int slen[4];
} gr_info;

extern gr_info *cod_info;
extern int k;
extern int max_slen1;
extern int max_slen2;
extern int ep;
extern int slen1[16];
extern int slen2[16];
extern int *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, we access slen1, slen2, and tab with a stride of 2, then handle remaining indices in a second pass.
    int stride = 2;
    for (k = 0; k < 16; k += stride) {
        // Access current and next index if within bounds
        int k1 = k;
        int k2 = k + 1;

        // Process k1
        if ((max_slen1 < slen1[k1]) && (max_slen2 < slen2[k1]) && ((int)cod_info->part2_length > tab[k1])) {
            cod_info->part2_length = tab[k1];
            cod_info->scalefac_compress = k1;
            ep = 0;
        }

        // Process k2 if valid
        if (k2 < 16) {
            if ((max_slen1 < slen1[k2]) && (max_slen2 < slen2[k2]) && ((int)cod_info->part2_length > tab[k2])) {
                cod_info->part2_length = tab[k2];
                cod_info->scalefac_compress = k2;
                ep = 0;
            }
        }
    }
}
