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
    for (int j = 0; j < c->nb_groups; j++) {
        for (int k = 0; k < 1; k++) { // Artificially increased nesting depth with a single iteration inner loop
            c->groups[j] = frm_ofs_tab[seg_id][c->gr_code][j];
            if (c->nb_mstr_exp == 2) {
                c->groups[j].nb_exponent -= c->bw_code;
                c->groups[j].nb_bias_exp[1] -= c->bw_code;
            }
        }
    }
}
