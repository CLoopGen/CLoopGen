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

DBEChannel *c;
DBEGroup *g;
int mstr_exp[2];
int bias_exp[50];
int i;
int j;
int k;

static uint8_t static_nb_mantissa_data[8] = {1, 2, 3, 4, 5, 6, 7, 8};

void init_vars() {
    c = (DBEChannel*)aligned_alloc(32, sizeof(DBEChannel));
    g = (DBEGroup*)aligned_alloc(16, sizeof(DBEGroup));

    if (!c || !g) {
        exit(1);
    }

    for (int idx = 0; idx < 8; ++idx) {
        c->groups[idx].nb_exponent = 1;
        c->groups[idx].nb_bias_exp[0] = 10;
        c->groups[idx].nb_bias_exp[1] = 10;
        c->groups[idx].exp_ofs = idx * 38;
        c->groups[idx].mnt_ofs = 0;
        c->groups[idx].nb_mantissa = &static_nb_mantissa_data[idx];
        c->groups[idx].imdct_idx = 0;
        c->groups[idx].imdct_phs = 0;
        c->groups[idx].win_len = 256;
        c->groups[idx].dst_ofs = 0;
        c->groups[idx].win_ofs = 0;
        c->groups[idx].src_ofs = 0;
    }

    c->nb_mstr_exp = 2;
    g->nb_bias_exp[0] = 25;
    g->nb_bias_exp[1] = 25;
    g->exp_ofs = 0;
    g->mnt_ofs = 0;
    g->nb_mantissa = &static_nb_mantissa_data[0];

    for (int i = 0; i < 2; ++i) {
        mstr_exp[i] = 5 + i * 3;
    }

    for (int k = 0; k < 50; ++k) {
        bias_exp[k] = k % 7 - 3;
    }

    for (int i = 0; i < 304; ++i) {
        c->exponents[i] = 0;
        c->bap[i] = 0;
        c->idx[i] = 0;
    }

    for (int i = 0; i < 1024; ++i) {
        c->mantissas[i] = 0.0f;
    }
}