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
for (i = 0; i < c->nb_groups; i++) {
    DBEGroup temp = frm_ofs_tab[seg_id][c->gr_code][i];
    c->groups[i] = temp;
    int should_adjust = (c->nb_mstr_exp == 2);
    if (!should_adjust) continue;
    c->groups[i].nb_exponent -= c->bw_code;
    c->groups[i].nb_bias_exp[1] -= c->bw_code;
}
}
