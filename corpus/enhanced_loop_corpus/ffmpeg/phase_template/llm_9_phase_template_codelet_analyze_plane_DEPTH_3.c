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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *loop_nptr = nptr;
    uint16_t *loop_optr = optr;
    rend = nptr + w;
    int stride = 2;
    for (int j = 0; j < w; j += stride) {
        int limit = (j + stride <= w) ? j + stride : w;
        for (int k = j; k < limit; k++) {
            int t_n = ((*loop_nptr) - loop_nptr[ns]) << 2;
            int t_n_add = loop_nptr[(ns) << 1] - loop_nptr[-ns];
            int t_val_n = t_n + t_n_add;
            pdif += t_val_n * t_val_n;

            int t_b = ((*loop_nptr) - loop_optr[os]) << 2;
            int t_b_add = loop_nptr[(ns) << 1] - loop_optr[-os];
            int t_val_b = t_b + t_b_add;
            bdif += t_val_b * t_val_b;

            loop_nptr++;
            loop_optr++;
        }
    }
}
