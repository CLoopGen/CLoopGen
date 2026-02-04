#include <stdio.h>
#include <stdlib.h>
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

gr_info *cod_info;
int partition;
int max_sfac[4];
int log2tab[256];

void init_vars() {
    cod_info = (gr_info*)malloc(sizeof(gr_info));
    if (!cod_info) return;
    cod_info->sfb_partition_table = (unsigned int*)malloc(16 * sizeof(unsigned int));
    for (int i = 0; i < 4; i++) {
        max_sfac[i] = 64 + i * 10;
    }
    for (int i = 0; i < 256; i++) {
        log2tab[i] = i > 0 ? (31 - __builtin_clz(i)) : 0;
    }
}