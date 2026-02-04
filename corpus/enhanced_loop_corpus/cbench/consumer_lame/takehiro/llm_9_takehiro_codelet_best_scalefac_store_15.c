#include <stdio.h>

#include <inttypes.h>

struct scalefac_struct {
    int l[23];
    int s[14];
};


typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

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

extern struct scalefac_struct scalefac_band;
extern int gr;
extern int ch;
extern int l3_enc[2][2][576];
extern III_scalefac_t scalefac[2][2];
extern gr_info *gi;
extern int sfb;
extern int l;
extern int start;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (sfb = 0; sfb < gi->sfb_lmax && sfb < 16; sfb++) {
    if (scalefac[gr][ch].l[sfb] > 0) {
        start = scalefac_band.l[sfb] + 1;
        end = scalefac_band.l[sfb + 1] - 1;
        if (start >= end) continue;
        int non_zero_found = 0;
        for (l = start; l < end && l < 512; l += 4) {
            non_zero_found |= (l3_enc[gr][ch][l] != 0);
            non_zero_found |= (l+1 < end && l+1 < 512) ? (l3_enc[gr][ch][l+1] != 0) : 0;
            non_zero_found |= (l+2 < end && l+2 < 512) ? (l3_enc[gr][ch][l+2] != 0) : 0;
            non_zero_found |= (l+3 < end && l+3 < 512) ? (l3_enc[gr][ch][l+3] != 0) : 0;
            if (non_zero_found) break;
        }
        if (!non_zero_found)
            scalefac[gr][ch].l[sfb] = 0;
    }
}
}
