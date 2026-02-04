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
    // Variant 1: Consecutive Memory Access with Unrolling (factor of 2)
    // Arrays are accessed in a more sequential and coalesced pattern by unrolling the loop.
    // This improves cache locality and reduces address computation overhead.

    uint16_t *nend = nptr + w;
    uint16_t *oend = optr + w;

    for (rend = nend; nptr < rend - 1; ) {
        // First element in unrolled pair
        int t1_n_ns = nptr[ns];
        int t1_n_2ns = nptr[(ns) << 1];
        int t1_n_neg_ns = nptr[-(ns)];
        int t1_val = ((*nptr - t1_n_ns) << 2) + t1_n_2ns - t1_n_neg_ns;
        pdif += t1_val * t1_val;

        int t1_o_os = optr[os];
        int t1_o_neg_os = optr[-(os)];
        int t1_val_op = ((*nptr - t1_o_os) << 2) + t1_n_2ns - t1_o_neg_os;
        tdif += t1_val_op * t1_val_op;

        int t1_op_val = (*optr);
        int t1_op_2os = optr[(os) << 1];
        int t1_val_bd = ((t1_op_val - t1_n_ns) << 2) + t1_op_2os - t1_n_neg_ns;
        bdif += t1_val_bd * t1_val_bd;

        nptr++;
        optr++;

        // Second element in unrolled pair
        int t2_n_ns = nptr[ns];
        int t2_n_2ns = nptr[(ns) << 1];
        int t2_n_neg_ns = nptr[-(ns)];
        int t2_val = ((*nptr - t2_n_ns) << 2) + t2_n_2ns - t2_n_neg_ns;
        pdif += t2_val * t2_val;

        int t2_o_os = optr[os];
        int t2_o_neg_os = optr[-(os)];
        int t2_val_op = ((*nptr - t2_o_os) << 2) + t2_n_2ns - t2_o_neg_os;
        tdif += t2_val_op * t2_val_op;

        int t2_op_val = (*optr);
        int t2_op_2os = optr[(os) << 1];
        int t2_val_bd = ((t2_op_val - t2_n_ns) << 2) + t2_op_2os - t2_n_neg_ns;
        bdif += t2_val_bd * t2_val_bd;

        nptr++;
        optr++;
    }

    // Handle leftover element if width is odd
    if (nptr < rend) {
        t = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
        pdif += t * t;
        t = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)];
        tdif += t * t;
        t = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)];
        bdif += t * t;
        nptr++;
        optr++;
    }
}
