#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

typedef struct cook_gains {
    int *now;
    int *previous;
} cook_gains;

typedef struct COOKSubpacket {
    int ch_idx;
    int size;
    int num_channels;
    int cookversion;
    int subbands;
    int js_subband_start;
    int js_vlc_bits;
    int samples_per_channel;
    int log2_numvector_size;
    unsigned int channel_mask;
    VLC channel_coupling;
    int joint_stereo;
    int bits_per_subpacket;
    int bits_per_subpdiv;
    int total_subbands;
    int numvector_size;
    float mono_previous_buffer1[1024];
    float mono_previous_buffer2[1024];
    cook_gains gains1;
    cook_gains gains2;
    int gain_1[9];
    int gain_2[9];
    int gain_3[9];
    int gain_4[9];
} COOKSubpacket;

COOKSubpacket *p;
float *decode_buffer;
float *mlt_buffer1;
float *mlt_buffer2;
int subband;
float f1;
float f2;
int j;
int tmp_idx;

static int16_t(*v_table)[2];
static int *gains_now1, *gains_previous1;
static int *gains_now2, *gains_previous2;
static float *decode_buffer_data;
static float *mlt_buffer1_data;
static float *mlt_buffer2_data;

void init_vars() {
    v_table = calloc(1024, sizeof(*v_table));
    
    gains_now1 = calloc(9, sizeof(int));
    gains_previous1 = calloc(9, sizeof(int));
    gains_now2 = calloc(9, sizeof(int));
    gains_previous2 = calloc(9, sizeof(int));
    
    for (int i = 0; i < 9; i++) {
        gains_now1[i] = 1;
        gains_previous1[i] = 1;
        gains_now2[i] = 1;
        gains_previous2[i] = 1;
    }

    decode_buffer_data = malloc(16777216 * sizeof(float));
    mlt_buffer1_data = calloc(16777216, sizeof(float));
    mlt_buffer2_data = calloc(16777216, sizeof(float));
    
    for (int i = 0; i < 16777216; i++) {
        decode_buffer_data[i] = 1.0f;
    }

    p = malloc(sizeof(COOKSubpacket));
    p->js_subband_start = 0;
    p->subbands = 8192;
    p->channel_coupling.table = v_table;
    p->gains1.now = gains_now1;
    p->gains1.previous = gains_previous1;
    p->gains2.now = gains_now2;
    p->gains2.previous = gains_previous2;
    p->numvector_size = 20;

    decode_buffer = decode_buffer_data;
    mlt_buffer1 = mlt_buffer1_data;
    mlt_buffer2 = mlt_buffer2_data;

    subband = 0;
    f1 = 0.5f;
    f2 = 0.5f;
}