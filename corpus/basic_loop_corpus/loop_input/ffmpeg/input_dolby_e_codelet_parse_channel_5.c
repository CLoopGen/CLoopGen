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

static uint8_t nb_mantissa_data[2][4][8];
static DBEGroup frm_ofs_tab_storage[2][4][8];
DBEGroup * frm_ofs_tab[2][4];

int seg_id;
DBEChannel *c;
int i;

void init_vars() {
    seg_id = 1;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 4; b++) {
            for (int g = 0; g < 8; g++) {
                DBEGroup *grp = &frm_ofs_tab_storage[a][b][g];
                grp->nb_exponent = 5 + (a * 4 + b + g) % 10;
                grp->nb_bias_exp[0] = 3 + ((a + b) % 8);
                grp->nb_bias_exp[1] = 4 + ((b + g) % 8);
                grp->exp_ofs = 100 + g * 10;
                grp->mnt_ofs = 200 + g * 20;
                grp->nb_mantissa = &nb_mantissa_data[a][b][g];
                grp->imdct_idx = g % 3;
                grp->imdct_phs = (a + b) % 2;
                grp->win_len = 512;
                grp->dst_ofs = g * 128;
                grp->win_ofs = g * 64;
                grp->src_ofs = g * 32;
            }
            frm_ofs_tab[a][b] = frm_ofs_tab_storage[a][b];
        }
    }

    c = (DBEChannel*)aligned_alloc(32, sizeof(DBEChannel));
    if (!c) exit(1);

    c->gr_code = 2;
    c->bw_code = 1;
    c->nb_groups = 8;
    c->nb_mstr_exp = 2;

    for (int j = 0; j < 8; j++) {
        c->exp_strategy[j] = j % 2;
    }
    for (int j = 0; j < 304; j++) {
        c->exponents[j] = 10 + (j % 15);
        c->bap[j] = j % 16;
        c->idx[j] = j % 8;
    }
    for (int j = 0; j < 1024; j++) {
        c->mantissas[j] = 0.5f + (j % 100) * 0.01f;
    }
}