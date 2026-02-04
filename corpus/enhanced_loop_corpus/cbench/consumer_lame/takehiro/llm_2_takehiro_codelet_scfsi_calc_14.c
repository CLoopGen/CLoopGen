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

extern int i;
extern int s1;
extern int s2;
extern int c1;
extern int c2;
extern gr_info *gi;
extern  int slen1_n[16];
extern  int slen2_n[16];
extern  int slen1_tab[16];
extern  int slen2_tab[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Arrays are accessed with a stride of 2, reducing iterations but still covering the range with offset handling
    for (i = 0; i < 16; i += 2) {
        int idx = i;
        if (idx < 16 && s1 < slen1_n[idx] && s2 < slen2_n[idx]) {
            int c = slen1_tab[idx] * c1 + slen2_tab[idx] * c2;
            if ((int)gi->part2_length > c) {
                gi->part2_length = c;
                gi->scalefac_compress = idx;
            }
        }
        idx = i + 1;
        if (idx < 16 && s1 < slen1_n[idx] && s2 < slen2_n[idx]) {
            int c = slen1_tab[idx] * c1 + slen2_tab[idx] * c2;
            if ((int)gi->part2_length > c) {
                gi->part2_length = c;
                gi->scalefac_compress = idx;
            }
        }
    }
}
