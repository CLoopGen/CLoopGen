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

struct scalefac_struct scalefac_band;
int gr = 0;
int ch = 0;
int l3_enc[2][2][576];
III_scalefac_t scalefac[2][2];
gr_info *gi;
int sfb;
int i;
int l;
int start;
int end;

static gr_info gi_storage;

void init_vars() {
    gr = 0;
    ch = 0;
    sfb = 0;
    i = 0;
    l = 0;
    start = 0;
    end = 0;

    for (int idx = 0; idx < 23; idx++) {
        scalefac_band.l[idx] = idx * 10;
    }
    for (int idx = 0; idx < 14; idx++) {
        scalefac_band.s[idx] = idx * 12;
    }

    for (int g = 0; g < 2; g++) {
        for (int c = 0; c < 2; c++) {
            for (int idx = 0; idx < 22; idx++) {
                scalefac[g][c].l[idx] = (g + c) * idx;
            }
            for (int sfb_idx = 0; sfb_idx < 13; sfb_idx++) {
                for (int j = 0; j < 3; j++) {
                    scalefac[g][c].s[sfb_idx][j] = (g + c + sfb_idx + j) % 5;
                }
            }
        }
    }

    for (int g = 0; g < 2; g++) {
        for (int c = 0; c < 2; c++) {
            for (int idx = 0; idx < 576; idx++) {
                l3_enc[g][c][idx] = (idx % 7) ? 0 : 1;
            }
        }
    }

    gi_storage.sfb_smax = 8;
    gi_storage.sfb_partition_table = NULL;
    gi = &gi_storage;
}