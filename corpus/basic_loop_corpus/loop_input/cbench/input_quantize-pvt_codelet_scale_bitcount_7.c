#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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
int k;
int max_slen1;
int max_slen2;
int ep;
int slen1[16];
int slen2[16];
int *tab;

void init_vars() {
    cod_info = (gr_info*)malloc(sizeof(gr_info));
    if (!cod_info) exit(1);

    cod_info->part2_length = 1000;
    cod_info->scalefac_compress = 0;
    cod_info->sfb_partition_table = (unsigned int*)malloc(512 * sizeof(unsigned int));
    for (int i = 0; i < 512; ++i)
        cod_info->sfb_partition_table[i] = i % 256;

    max_slen1 = 5;
    max_slen2 = 5;

    ep = 1;

    for (int i = 0; i < 16; ++i) {
        slen1[i] = (i % 8) + 1;
        slen2[i] = (i % 8) + 1;
    }

    tab = (int*)malloc(16 * sizeof(int));
    if (!tab) exit(1);
    for (int i = 0; i < 16; ++i)
        tab[i] = 20 - i;
}