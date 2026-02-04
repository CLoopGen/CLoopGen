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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // Arrays are accessed in a consecutive manner by precomputing base offsets and stepping linearly.
    // This variant assumes w is even for simplicity.

    uint16_t *nptr_end = nptr + w;
    uint16_t *optr_base = optr;

    for (; nptr < nptr_end; nptr += 2, optr += 2) {
        // First element
        int t1_n = (*nptr - nptr[ns]) << 2;
        int t1_n_prev = nptr[(ns) << 1] - nptr[-ns];
        int t1 = t1_n + t1_n_prev;
        pdif += t1 * t1;

        int t1_o = (*nptr - optr[os]) << 2;
        int t1_o_prev = nptr[(ns) << 1] - optr[-os];
        int t1t = t1_o + t1_o_prev;
        tdif += t1t * t1t;

        int t1_b = (*optr - nptr[ns]) << 2;
        int t1_b_prev = optr[(os) << 1] - nptr[-ns];
        int t1b = t1_b + t1_b_prev;
        bdif += t1b * t1b;

        // Second element (if within bounds)
        if (nptr + 1 < nptr_end) {
            int t2_n = (*(nptr+1) - (nptr+1)[ns]) << 2;
            int t2_n_prev = (nptr+1)[(ns)<<1] - (nptr+1)[-ns];
            int t2 = t2_n + t2_n_prev;
            pdif += t2 * t2;

            int t2_o = (*(nptr+1) - (optr+1)[os]) << 2;
            int t2_o_prev = (nptr+1)[(ns)<<1] - (optr+1)[-os];
            int t2t = t2_o + t2_o_prev;
            tdif += t2t * t2t;

            int t2_b = (*(optr+1) - (nptr+1)[ns]) << 2;
            int t2_b_prev = (optr+1)[(os)<<1] - (nptr+1)[-ns];
            int t2b = t2_b + t2_b_prev;
            bdif += t2b * t2b;
        }
    }
}
