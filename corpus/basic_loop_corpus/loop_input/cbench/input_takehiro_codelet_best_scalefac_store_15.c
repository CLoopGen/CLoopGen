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
int l;
int start;
int end;

static unsigned int sfb_partition_data[22];
static gr_info gi_storage;

void init_vars() {
    gr = 0;
    ch = 0;
    sfb = 0;
    l = 0;
    start = 0;
    end = 0;

    for (int i = 0; i < 23; i++) {
        scalefac_band.l[i] = i * 24;
    }
    for (int i = 0; i < 14; i++) {
        scalefac_band.s[i] = i * 12;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 22; k++) {
                scalefac[i][j].l[k] = (k < 16) ? 1 : 0;
            }
            for (int k = 0; k < 13; k++) {
                for (int m = 0; m < 3; m++) {
                    scalefac[i][j].s[k][m] = 1;
                }
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 576; k++) {
                l3_enc[i][j][k] = (k % 97 == 0) ? 1 : 0;
            }
        }
    }

    for (int i = 0; i < 22; i++) {
        sfb_partition_data[i] = i;
    }

    gi_storage.sfb_lmax = 21;
    gi_storage.sfb_smax = 13;
    gi_storage.sfb_partition_table = sfb_partition_data;
    gi = &gi_storage;
}