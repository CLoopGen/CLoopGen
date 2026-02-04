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

extern  int expbits_tab[8];
extern COOKSubpacket *p;
extern  int *quant_index_table;
extern int bias;
extern int tmpbias1;
extern int tmpbias2;
extern int bits_left;
extern int _usr_index;
extern int v;
extern int i;
extern int j;
extern int exp_index2[102];
extern int exp_index1[102];
extern int tmp_categorize_array[256];
extern int tmp_categorize_array1_idx;
extern int tmp_categorize_array2_idx;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Consecutive memory access pattern using local array to accumulate indices
    // Instead of writing directly to scattered positions in tmp_categorize_array,
    // we use two local buffers for sequential writes and copy back at the end.
    
    int temp_array1[512]; // Assuming max size needed
    int temp_array2[512];
    int idx1 = 0, idx2 = 0;
    int local_bias1 = tmpbias1;
    int local_bias2 = tmpbias2;
    int local_exp_index1[102];
    int local_exp_index2[102];

    // Copy input arrays to local stacks for better locality
    for (i = 0; i < p->total_subbands; i++) {
        local_exp_index1[i] = exp_index1[i];
        local_exp_index2[i] = exp_index2[i];
    }

    for (j = 1; j < p->numvector_size; j++) {
        if (local_bias1 + local_bias2 > 2 * bits_left) {
            int max = -999999;
            index = -1;
            for (i = 0; i < p->total_subbands; i++) {
                if (local_exp_index1[i] < 7) {
                    v = (-2 * local_exp_index1[i]) - quant_index_table[i] + bias;
                    if (v >= max) {
                        max = v;
                        index = i;
                    }
                }
            }
            if (index == -1)
                break;
            temp_array1[idx1++] = index;
            local_bias1 -= expbits_tab[local_exp_index1[index]] - expbits_tab[local_exp_index1[index] + 1];
            ++local_exp_index1[index];
        } else {
            int min = 999999;
            index = -1;
            for (i = 0; i < p->total_subbands; i++) {
                if (local_exp_index2[i] > 0) {
                    v = (-2 * local_exp_index2[i]) - quant_index_table[i] + bias;
                    if (v < min) {
                        min = v;
                        index = i;
                    }
                }
            }
            if (index == -1)
                break;
            temp_array2[idx2++] = index;
            local_bias2 -= expbits_tab[local_exp_index2[index]] - expbits_tab[local_exp_index2[index] - 1];
            --local_exp_index2[index];
        }
    }

    // Write accumulated results back to global arrays with consecutive access
    for (i = 0; i < idx1; i++) {
        tmp_categorize_array[tmp_categorize_array1_idx + i] = temp_array1[i];
    }
    tmp_categorize_array1_idx += idx1;

    for (i = 0; i < idx2; i++) {
        tmp_categorize_array[tmp_categorize_array2_idx - idx2 + i] = temp_array2[i];
    }
    tmp_categorize_array2_idx -= idx2;

    // Update global state
    tmpbias1 = local_bias1;
    tmpbias2 = local_bias2;
    for (i = 0; i < p->total_subbands; i++) {
        exp_index1[i] = local_exp_index1[i];
        exp_index2[i] = local_exp_index2[i];
    }
}
