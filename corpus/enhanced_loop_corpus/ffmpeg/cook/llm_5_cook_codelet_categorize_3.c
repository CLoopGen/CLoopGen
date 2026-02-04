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
for (j = 1; j < p->numvector_size; j++) {
    int condition = (tmpbias1 + tmpbias2 > 2 * bits_left);
    int candidate_found = 0;

    // Unified search with conditional behavior embedded in comparison logic
    index = -1;
    for (i = 0; i < p->total_subbands; i++) {
        int valid1 = (condition && exp_index1[i] < 7);
        int valid2 = (!condition && exp_index2[i] > 0);
        
        if (valid1 || valid2) {
            v = (-2 * (condition ? exp_index1[i] : exp_index2[i])) - quant_index_table[i] + bias;
            if (!candidate_found) {
                index = i;
                candidate_found = 1;
            } else {
                int current_val = (condition ? exp_index1[index] : exp_index2[index]);
                int compare_val = (condition ? exp_index1[i] : exp_index2[i]);
                int existing_score = (-2 * current_val) - quant_index_table[index] + bias;
                int new_score = v;

                if ((condition && new_score >= existing_score) ||
                    (!condition && new_score < existing_score)) {
                    index = i;
                }
            }
        }
    }

    if (index == -1) continue;

    if (condition) {
        tmp_categorize_array[tmp_categorize_array1_idx++] = index;
        tmpbias1 -= expbits_tab[exp_index1[index]] - expbits_tab[exp_index1[index] + 1];
        ++exp_index1[index];
    } else {
        tmp_categorize_array[--tmp_categorize_array2_idx] = index;
        tmpbias2 -= expbits_tab[exp_index2[index]] - expbits_tab[exp_index2[index] - 1];
        --exp_index2[index];
    }
}
}
