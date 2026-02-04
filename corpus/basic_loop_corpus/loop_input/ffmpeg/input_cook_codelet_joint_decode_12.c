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
float *mlt_buffer_left;
float *mlt_buffer_right;
int i;
int j;
float *decode_buffer;

static float *mlt_buffer_left_data;
static float *mlt_buffer_right_data;
static float *decode_buffer_data;
static COOKSubpacket p_data;

void init_vars() {
    const int data_size = 1 << 20; // ~4MB of decode_buffer (1M floats)
    
    mlt_buffer_left_data = (float*)calloc(data_size, sizeof(float));
    mlt_buffer_right_data = (float*)calloc(data_size, sizeof(float));
    decode_buffer_data = (float*)calloc(data_size * 2, sizeof(float));

    if (!mlt_buffer_left_data || !mlt_buffer_right_data || !decode_buffer_data) {
        exit(1);
    }

    mlt_buffer_left = mlt_buffer_left_data;
    mlt_buffer_right = mlt_buffer_right_data;
    decode_buffer = decode_buffer_data;

    p = &p_data;
    p->js_subband_start = data_size / 20; // ensures we use most of buffer without overflow
    if (p->js_subband_start > 50000) {
        p->js_subband_start = 50000; // cap to prevent overflow in decode_buffer access
    }
}