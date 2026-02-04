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

extern ALSSpecificConfig *sconf;
extern int sb;
extern int32_t *raw_samples;
extern uint32_t *left;
extern uint32_t *right;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (sb = -1; sb >= -sconf->max_order; sb--)
    raw_samples[sb] = right[sb] - left[sb];

}
