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
int i;

void init_vars() {
    cod_info = (gr_info*)malloc(sizeof(gr_info));
    if (!cod_info) return;

    cod_info->part2_3_length = 0;
    cod_info->big_values = 0;
    cod_info->count1 = 0;
    cod_info->global_gain = 0;
    cod_info->scalefac_compress = 0;
    cod_info->window_switching_flag = 0;
    cod_info->block_type = 0;
    cod_info->mixed_block_flag = 0;
    for (int j = 0; j < 3; j++) {
        cod_info->table_select[j] = 0;
        cod_info->subblock_gain[j] = 0;
    }
    cod_info->region0_count = 0;
    cod_info->region1_count = 0;
    cod_info->preflag = 0;
    cod_info->scalefac_scale = 0;
    cod_info->count1table_select = 0;
    cod_info->part2_length = 0;
    cod_info->sfb_lmax = 0;
    cod_info->sfb_smax = 0;
    cod_info->count1bits = 0;

    cod_info->sfb_partition_table = (unsigned int*)calloc(1, sizeof(unsigned int));
    if (!cod_info->sfb_partition_table) {
        free(cod_info);
        cod_info = NULL;
        return;
    }

    for (int j = 0; j < 4; j++) {
        cod_info->slen[j] = 0;
    }

    i = 0;
}