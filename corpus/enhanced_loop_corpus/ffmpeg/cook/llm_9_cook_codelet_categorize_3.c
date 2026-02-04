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
    int step = (p->cookversion > 5) ? 1 : 2;
    int limit = p->numvector_size >> 1;
    for (j = 2; j < limit; j++) {
        int combined_bias = tmpbias1 + tmpbias2;
        int threshold = 3 * bits_left;

        if (combined_bias > threshold) {
            int candidate_count = 0;
            int candidates[32];
            for (i = 0; i < p->total_subbands && candidate_count < 32; i++) {
                if (exp_index1[i] < 7) {
                    v = (-2 * exp_index1[i]) - quant_index_table[i] + bias;
                    int insert_pos = 0;
                    while (insert_pos < candidate_count && (-2 * exp_index1[candidates[insert_pos]]) - quant_index_table[candidates[insert_pos]] + bias >= v)
                        insert_pos++;
                    if (candidate_count < 32) {
                        for (int k = candidate_count; k > insert_pos; k--)
                            candidates[k] = candidates[k - 1];
                        candidates[insert_pos] = i;
                        candidate_count++;
                    }
                }
            }
            if (candidate_count == 0) break;
            index = candidates[0];
            tmp_categorize_array[tmp_categorize_array1_idx++] = index;
            tmpbias1 -= expbits_tab[exp_index1[index]] - expbits_tab[exp_index1[index] + 1];
            ++exp_index1[index];
        } else {
            int found = 0;
            for (i = p->total_subbands - 1; i >= 0 && !found; i--) {
                if (exp_index2[i] > 0) {
                    v = (-2 * exp_index2[i]) - quant_index_table[i] + bias;
                    if (v <= 0) {
                        index = i;
                        tmp_categorize_array[--tmp_categorize_array2_idx] = index;
                        tmpbias2 -= expbits_tab[exp_index2[index]] - expbits_tab[exp_index2[index] - 1];
                        --exp_index2[index];
                        found = 1;
                    }
                }
            }
            if (!found) break;
        }
        if (tmp_categorize_array1_idx - tmp_categorize_array2_idx > 128) break;
    }
}
