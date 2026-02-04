#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

ALSSpecificConfig *sconf;
int sb;
int32_t *raw_samples;
uint32_t *left;
uint32_t *right;

void init_vars() {
    sconf = (ALSSpecificConfig*)malloc(sizeof(ALSSpecificConfig));
    sconf->max_order = 1024;

    size_t data_size = (sconf->max_order + 1) * sizeof(int32_t);

    raw_samples = (int32_t*)malloc(data_size);
    left = (uint32_t*)malloc(data_size);
    right = (uint32_t*)malloc(data_size);

    for (int i = 0; i <= sconf->max_order; i++) {
        raw_samples[-i] = 0;
        left[-i] = (uint32_t)(i * 3);
        right[-i] = (uint32_t)(i * 5);
    }

    sb = 0;
}