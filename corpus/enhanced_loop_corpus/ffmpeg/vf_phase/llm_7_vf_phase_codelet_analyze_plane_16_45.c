#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t bdif;
extern int64_t tdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *temp_nptr = nptr;
    uint16_t *temp_optr = optr;
    int64_t temp_bdif = 0;
    int64_t temp_tdif = 0;
    uint16_t *loop_rend = nptr + w;
    while (temp_nptr < loop_rend) {
        int diff_n_optr = (*temp_nptr - temp_optr[os]);
        int n_shifted = temp_nptr[ns << 1];
        int o_neg = temp_optr[-os];
        int val_b = (diff_n_optr << 2) + n_shifted - o_neg;
        temp_bdif += val_b * val_b;

        int diff_o_nptr = (*temp_optr - temp_nptr[ns]);
        int o_shifted = temp_optr[os << 1];
        int n_neg = temp_nptr[-ns];
        int val_t = (diff_o_nptr << 2) + o_shifted - n_neg;
        temp_tdif += val_t * val_t;

        temp_nptr++;
        temp_optr++;
    }
    bdif += temp_bdif;
    tdif += temp_tdif;
}
