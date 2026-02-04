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
int *category_index;
int i;
int tmp_categorize_array[256];
int tmp_categorize_array2_idx;

static COOKSubpacket p_storage;
static int *now_ptr;
static int *previous_ptr;
static int category_index_storage[1024];

void init_vars() {
    const int data_size = 1 << 20; // ~1MB of input data for ~0.01 sec runtime estimate

    // Allocate and initialize now and previous arrays for gains
    now_ptr = (int*)calloc(9, sizeof(int));
    previous_ptr = (int*)calloc(9, sizeof(int));
    if (!now_ptr || !previous_ptr) {
        exit(1);
    }

    // Initialize p_storage
    p_storage.numvector_size = data_size;
    p_storage.gains1.now = now_ptr;
    p_storage.gains1.previous = previous_ptr;
    p_storage.gains2.now = now_ptr;
    p_storage.gains2.previous = previous_ptr;

    // Initialize VLC table to avoid dangling pointers
    p_storage.channel_coupling.table = NULL;

    // Set p to point to the storage
    p = &p_storage;

    // Initialize category_index to point to allocated buffer
    category_index = category_index_storage;

    // Ensure tmp_categorize_array2_idx starts at a valid position
    // and does not exceed bounds during loop execution
    tmp_categorize_array2_idx = 0;

    // Initialize tmp_categorize_array with dummy values to prevent undefined behavior
    for (int j = 0; j < 256; j++) {
        tmp_categorize_array[j] = j % 16;
    }

    // Resize effective numvector_size so that we don't overflow tmp_categorize_array
    // since we are reading from it with incrementing index
    // We limit numvector_size to the size of tmp_categorize_array
    p->numvector_size = 256;
}