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
extern int i;
extern int l;
extern int start;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++) {
    for (sfb = gi->sfb_smax; sfb < 12; sfb++) {
        int should_zero = 1;
        if (scalefac[gr][ch].s[sfb][i] > 0) {
            start = scalefac_band.s[sfb];
            end = scalefac_band.s[sfb + 1];
            for (l = start; l < end; l++) {
                if (l3_enc[gr][ch][3 * l + i] != 0) {
                    should_zero = 0;
                    break;
                }
            }
            if (should_zero) {
                scalefac[gr][ch].s[sfb][i] = 0;
            }
        }
    }
}
}
