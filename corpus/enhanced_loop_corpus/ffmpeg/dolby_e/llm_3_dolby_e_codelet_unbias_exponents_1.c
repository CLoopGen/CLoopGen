#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct DBEGroup {
    uint8_t nb_exponent;
    uint8_t nb_bias_exp[2];
    uint16_t exp_ofs;
    uint16_t mnt_ofs;
    const uint8_t *nb_mantissa;
    uint8_t imdct_idx;
    uint8_t imdct_phs;
    uint16_t win_len;
    uint16_t dst_ofs;
    uint16_t win_ofs;
    uint16_t src_ofs;
} DBEGroup;

typedef struct DBEChannel {
    int gr_code;
    int bw_code;
    int nb_groups;
    int nb_mstr_exp;
    DBEGroup groups[8];
    int exp_strategy[8];
    int exponents[304];
    int bap[304];
    int idx[304];
    float mantissas[1024] __attribute__((aligned(32)));
} DBEChannel;

extern DBEChannel *c;
extern DBEGroup *g;
extern int mstr_exp[2];
extern int bias_exp[50];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect array access using index remapping
    // Use an auxiliary array to define a non-trivial access pattern into exponents
    uint16_t indices[304];  // Assume max size needed
    for (i = k = 0; i < c->nb_mstr_exp; i++) {
        for (j = 0; j < g->nb_bias_exp[i]; j++, k++) {
            indices[k] = g->exp_ofs + k;  // Could be randomized or reordered in practice
        }
    }
    // Now perform the write using indirect addressing
    for (k = 0; k < c->nb_mstr_exp * g->nb_bias_exp[0]; k++) {  // Conservative bound
        if (k >= 304) break;
        int i_idx = 0;
        int accumulated = 0;
        while (i_idx < c->nb_mstr_exp && accumulated + g->nb_bias_exp[i_idx] <= k) {
            accumulated += g->nb_bias_exp[i_idx++];
        }
        int local_k = k - accumulated;
        c->exponents[indices[k]] = mstr_exp[i_idx] + bias_exp[k];
    }
}
