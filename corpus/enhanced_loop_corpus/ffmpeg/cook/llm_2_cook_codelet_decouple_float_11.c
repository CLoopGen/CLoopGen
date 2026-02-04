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

extern COOKSubpacket *p;
extern int subband;
extern float f1;
extern float f2;
extern float *decode_buffer;
extern float *mlt_buffer1;
extern float *mlt_buffer2;
extern int j;
extern int tmp_idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling for spatial locality
    int base_idx = (p->js_subband_start + subband) * 20;
    int base_mlt = 20 * subband;
    float tmp_val;

    for (j = 0; j < 20; j += 4) {
        // Unroll by 4 to promote consecutive and predictable access
        tmp_val = decode_buffer[base_idx + j];
        mlt_buffer1[base_mlt + j] = f1 * tmp_val;
        mlt_buffer2[base_mlt + j] = f2 * tmp_val;

        if (j+1 < 20) {
            tmp_val = decode_buffer[base_idx + j + 1];
            mlt_buffer1[base_mlt + j + 1] = f1 * tmp_val;
            mlt_buffer2[base_mlt + j + 1] = f2 * tmp_val;
        }

        if (j+2 < 20) {
            tmp_val = decode_buffer[base_idx + j + 2];
            mlt_buffer1[base_mlt + j + 2] = f1 * tmp_val;
            mlt_buffer2[base_mlt + j + 2] = f2 * tmp_val;
        }

        if (j+3 < 20) {
            tmp_val = decode_buffer[base_idx + j + 3];
            mlt_buffer1[base_mlt + j + 3] = f1 * tmp_val;
            mlt_buffer2[base_mlt + j + 3] = f2 * tmp_val;
        }
    }
}
