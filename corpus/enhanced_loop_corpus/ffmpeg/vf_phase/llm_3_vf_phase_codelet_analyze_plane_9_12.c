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
    // Variant 2: Strided memory access with increasing step size (stride = 4)
    const int stride = 4;
    rend = nptr + w;
    for (int i = 0; nptr + i < rend; i += stride) {
        uint16_t *n_cur = nptr + i;
        uint16_t *o_cur = optr + i;

        // Only process valid indices within bounds
        for (int j = 0; j < stride && (n_cur + j) < rend; j++) {
            int t_val;

            t_val = ((n_cur[j]) - o_cur[j + os]) << 2;
            t_val += n_cur[j + (ns << 1)] - o_cur[j - os];
            tdif += t_val * t_val;

            t_val = ((o_cur[j]) - n_cur[j + ns]) << 2;
            t_val += o_cur[j + (os << 1)] - n_cur[j - ns];
            bdif += t_val * t_val;
        }
    }
}
