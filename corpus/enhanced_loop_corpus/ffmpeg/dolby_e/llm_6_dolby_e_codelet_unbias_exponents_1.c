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
    int temp_exponents[304];
    for (i = k = 0; i < c->nb_mstr_exp; i++) {
        int base_exp = mstr_exp[i];
        for (j = 0; j < g->nb_bias_exp[i]; j++) {
            temp_exponents[g->exp_ofs + k] = base_exp + bias_exp[k];
            k++;
        }
    }
    for (int idx = 0; idx < k; idx++) {
        c->exponents[g->exp_ofs + idx] = temp_exponents[g->exp_ofs + idx];
    }
}
