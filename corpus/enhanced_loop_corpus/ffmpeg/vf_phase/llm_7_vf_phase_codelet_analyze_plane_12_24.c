#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t tdif;
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *rend_end = nptr + w;
    int64_t temp_sum_p = 0;
    int64_t temp_sum_t = 0;
    int i = 0;

    for (; i < w; i++) {
        int t_val;
        // Introduce WAW-like independence by computing both terms before update
        int diff_n = (nptr[i] - nptr[i + ns]) << 2;
        int n_ref = nptr[i + (ns << 1)] - nptr[i - ns];
        t_val = diff_n + n_ref;
        temp_sum_p += t_val * t_val;

        int diff_o = (nptr[i] - optr[i + os]) << 2;
        int o_ref = nptr[i + (ns << 1)] - optr[i - os];
        t_val = diff_o + o_ref;
        temp_sum_t += t_val * t_val;
    }
    // Accumulate into global sums only once at the end (reducing loop-carried dependency)
    pdif += temp_sum_p;
    tdif += temp_sum_t;
}
