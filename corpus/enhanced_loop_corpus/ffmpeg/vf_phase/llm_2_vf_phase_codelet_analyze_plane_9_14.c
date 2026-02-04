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
    // Variant 1: Consecutive memory access with unrolled stride of 2
    uint16_t *nend = nptr + w - 1;  // Adjust for unrolling by 2
    for (rend = nend; nptr < rend; nptr += 2, optr += 2) {
        // First element in unrolled pair
        int t1_n_cur = *(nptr);
        int t1_n_ns = nptr[ns];
        int t1_n_2ns = nptr[(ns) << 1];
        int t1_n_mns = nptr[-(ns)];
        int t1 = ((t1_n_cur - t1_n_ns) << 2) + t1_n_2ns - t1_n_mns;
        pdif += t1 * t1;

        int t1_o_os = optr[os];
        int t1_o_mos = optr[-(os)];
        int t1_t = ((t1_n_cur - t1_o_os) << 2) + t1_n_2ns - t1_o_mos;
        tdif += t1_t * t1_t;

        int t1_o_cur = *(optr);
        int t1_o_2os = optr[(os) << 1];
        int t1_b = ((t1_o_cur - t1_n_ns) << 2) + t1_o_2os - t1_n_mns;
        bdif += t1_b * t1_b;

        // Second element in unrolled pair
        int t2_n_cur = *(nptr + 1);
        int t2_n_ns = (nptr + 1)[ns];
        int t2_n_2ns = (nptr + 1)[(ns) << 1];
        int t2_n_mns = (nptr + 1)[-(ns)];
        int t2 = ((t2_n_cur - t2_n_ns) << 2) + t2_n_2ns - t2_n_mns;
        pdif += t2 * t2;

        int t2_o_os = (optr + 1)[os];
        int t2_o_mos = (optr + 1)[-(os)];
        int t2_t = ((t2_n_cur - t2_o_os) << 2) + t2_n_2ns - t2_o_mos;
        tdif += t2_t * t2_t;

        int t2_o_cur = *(optr + 1);
        int t2_o_2os = (optr + 1)[(os) << 1];
        int t2_b = ((t2_o_cur - t2_n_ns) << 2) + t2_o_2os - t2_n_mns;
        bdif += t2_b * t2_b;
    }

    // Handle remaining element if w is odd
    if (nptr <= nend + 1) {
        nptr = nend + 1;
        optr = optr - 1 + 1; // Sync optr to match nptr
        t = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
        pdif += t * t;
        t = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)];
        tdif += t * t;
        t = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)];
        bdif += t * t;
    }
}
