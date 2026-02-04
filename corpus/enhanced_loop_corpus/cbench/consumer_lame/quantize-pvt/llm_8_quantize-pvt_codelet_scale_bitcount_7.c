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
    int k1, k2;
    for (k1 = 0; k1 < 8; k1++) {
        for (k2 = 0; k2 < 2; k2++) {
            int idx = (k1 << 1) | k2;
            if ((max_slen1 < slen1[idx]) && (max_slen2 < slen2[idx]) && ((int)cod_info->part2_length > tab[idx])) {
                cod_info->part2_length = tab[idx];
                cod_info->scalefac_compress = idx;
                ep = 0;
            }
        }
    }
}
