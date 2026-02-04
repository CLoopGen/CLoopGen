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
    uint16_t *rend_end = nptr + w;
    int64_t temp_diff_accum = 0;

    for (int i = 0; nptr + i < rend_end; i++) {
        uint16_t n_val = nptr[i];
        uint16_t o_val = optr[i];
        uint16_t n_shift_forward = nptr[i + (ns << 1)];
        uint16_t o_shift_forward = optr[i + (os << 1)];
        uint16_t n_shift_backward = nptr[i - ns];
        uint16_t o_shift_backward = optr[i - os];

        int t_tdif = ((n_val - o_val) << 2) + n_shift_forward - o_shift_backward;
        int t_bdif = ((o_val - n_val) << 2) + o_shift_forward - n_shift_backward;

        temp_diff_accum += (t_tdif * t_tdif) + (t_bdif * t_bdif);
    }

    tdif += temp_diff_accum;
    bdif += temp_diff_accum;
}
