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

extern  DBEGroup * frm_ofs_tab[2][4];
extern int seg_id;
extern DBEChannel *c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (c->nb_groups + 1) / 2;
    for (i = 0; i < limit; i++) {
        DBEGroup tmp1 = frm_ofs_tab[seg_id][c->gr_code][i];
        c->groups[i] = tmp1;
        if (c->nb_mstr_exp == 2) {
            int adj = c->bw_code;
            c->groups[i].nb_exponent -= adj;
            c->groups[i].nb_bias_exp[0] = (c->groups[i].nb_bias_exp[0] >= adj) ? 
                                          c->groups[i].nb_bias_exp[0] - adj : 0;
        }
        if ((i + limit) < c->nb_groups) {
            DBEGroup tmp2 = frm_ofs_tab[seg_id][c->gr_code][i + limit];
            c->groups[i + limit] = tmp2;
            if (c->nb_mstr_exp == 2) {
                c->groups[i + limit].nb_exponent -= c->bw_code;
            }
        }
    }
}
