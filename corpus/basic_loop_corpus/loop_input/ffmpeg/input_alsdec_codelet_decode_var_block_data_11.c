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

ALSBlockData *bd;
ALSSpecificConfig *sconf;
int sb;
int32_t *raw_samples;

static unsigned int internal_shift_lsbs;
static int32_t *internal_raw_samples;
static ALSSpecificConfig sconf_instance;
static ALSBlockData bd_instance;

void init_vars() {
    sconf = &sconf_instance;
    bd = &bd_instance;

    sconf->max_order = 1024;

    bd->shift_lsbs = &internal_shift_lsbs;
    *bd->shift_lsbs = 1;

    size_t data_size = (sconf->max_order + 1) * sizeof(int32_t);
    internal_raw_samples = (int32_t*)calloc(1, data_size);
    if (!internal_raw_samples) {
        exit(1);
    }
    raw_samples = internal_raw_samples + sconf->max_order;

    for (int i = 0; i <= sconf->max_order; i++) {
        internal_raw_samples[i] = (int32_t)(0x7FFFFFFF - i);
    }

    bd->block_length = 0;
    bd->ra_block = 0;
    bd->const_block = NULL;
    bd->js_blocks = 0;
    bd->opt_order = NULL;
    bd->store_prev_samples = NULL;
    bd->use_ltp = NULL;
    bd->ltp_lag = NULL;
    bd->ltp_gain = NULL;
    bd->quant_cof = NULL;
    bd->lpc_cof = NULL;
    bd->prev_raw_samples = NULL;
    bd->raw_other = NULL;
}