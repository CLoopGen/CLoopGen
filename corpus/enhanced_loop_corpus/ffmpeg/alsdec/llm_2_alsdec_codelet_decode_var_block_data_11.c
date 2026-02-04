#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ALSBlockData {
    unsigned int block_length;
    unsigned int ra_block;
    int *const_block;
    int js_blocks;
    unsigned int *shift_lsbs;
    unsigned int *opt_order;
    int *store_prev_samples;
    int *use_ltp;
    int *ltp_lag;
    int *ltp_gain;
    int32_t *quant_cof;
    int32_t *lpc_cof;
    int32_t *raw_samples;
    int32_t *prev_raw_samples;
    int32_t *raw_other;
} ALSBlockData;

enum RA_Flag {
    RA_FLAG_NONE,
    RA_FLAG_FRAMES,
    RA_FLAG_HEADER
};


typedef struct ALSSpecificConfig {
    uint32_t samples;
    int resolution;
    int floating;
    int msb_first;
    int frame_length;
    int ra_distance;
    enum RA_Flag ra_flag;
    int adapt_order;
    int coef_table;
    int long_term_prediction;
    int max_order;
    int block_switching;
    int bgmc;
    int sb_part;
    int joint_stereo;
    int mc_coding;
    int chan_config;
    int chan_sort;
    int rlslms;
    int chan_config_info;
    int *chan_pos;
    int crc_enabled;
} ALSSpecificConfig;

extern ALSBlockData *bd;
extern ALSSpecificConfig *sconf;
extern int sb;
extern int32_t *raw_samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = -1;
    for (int i = 0; i < sconf->max_order; i++) {
        int idx = offset - i;
        raw_samples[idx] >>= bd->shift_lsbs[0];
    }
}
