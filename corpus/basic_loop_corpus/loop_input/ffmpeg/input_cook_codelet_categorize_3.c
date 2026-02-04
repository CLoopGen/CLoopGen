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

int expbits_tab[8] = {0, 1, 2, 3, 4, 5, 6, 7};

COOKSubpacket *p;
int *quant_index_table;
int bias;
int tmpbias1;
int tmpbias2;
int bits_left;
int _usr_index;
int v;
int i;
int j;
int exp_index2[102];
int exp_index1[102];
int tmp_categorize_array[256];
int tmp_categorize_array1_idx;
int tmp_categorize_array2_idx;

#define index _usr_index

void init_vars() {
    p = (COOKSubpacket*)calloc(1, sizeof(COOKSubpacket));
    if (!p) exit(1);

    p->total_subbands = 100;
    p->numvector_size = 100000;

    quant_index_table = (int*)malloc(p->total_subbands * sizeof(int));
    if (!quant_index_table) exit(1);

    for (int idx = 0; idx < p->total_subbands; ++idx) {
        quant_index_table[idx] = 10;
        exp_index1[idx] = idx % 7;
        exp_index2[idx] = (idx % 7) + 1;
    }

    bias = 20;
    tmpbias1 = 50000;
    tmpbias2 = 50000;
    bits_left = 20000;

    tmp_categorize_array1_idx = 0;
    tmp_categorize_array2_idx = 256;

    for (int idx = 0; idx < 256; ++idx) {
        tmp_categorize_array[idx] = 0;
    }
}

void loop();