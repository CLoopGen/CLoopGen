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
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        int64_t temp_bdif = 0;
        for (int i = 0; i < 2; i++) {
            int idx_n = (i == 0) ? 0 : ns << 1;
            int idx_o = (i == 0) ? os : -os;
            int t_val = ((nptr[idx_n] - optr[idx_o]) << 2) + nptr[(ns) << 1] - optr[-(os)];
            temp_bdif += t_val * t_val;
        }
        bdif += temp_bdif;

        int64_t temp_tdif = 0;
        for (int j = 0; j < 2; j++) {
            int idx_o = (j == 0) ? 0 : os << 1;
            int idx_n = (j == 0) ? ns : -ns;
            int t_val = ((optr[idx_o] - nptr[idx_n]) << 2) + optr[(os) << 1] - nptr[-(ns)];
            temp_tdif += t_val * t_val;
        }
        tdif += temp_tdif;
    }
}
