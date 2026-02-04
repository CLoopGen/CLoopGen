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
int *category;
int i;
int exp_index2[102];

void init_vars() {
    p = (COOKSubpacket*)calloc(1, sizeof(COOKSubpacket));
    if (!p) exit(1);

    p->total_subbands = 102;
    for (int j = 0; j < p->total_subbands; j++) {
        exp_index2[j] = j % 32;
    }

    category = (int*)malloc(p->total_subbands * sizeof(int));
    if (!category) exit(1);
}