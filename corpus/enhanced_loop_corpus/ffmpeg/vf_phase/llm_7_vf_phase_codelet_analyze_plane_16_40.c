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
    // Reverse iteration to change data access pattern and introduce anti-dependence (WAR)
    // Also unroll by 2 for instruction-level parallelism and modified update order
    uint16_t *rend = nptr + w;
    uint16_t *nptr_end = rend - (w % 2);  // Align to even boundary for unrolling

    // Process two elements per iteration, backwards
    for (nptr += w - 1, optr += w - 1; nptr >= nptr_end; nptr -= 2, optr -= 2) {
        int t_val1, t_val2;

        // First element (backwards)
        t_val1 = ((nptr[0] - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t_val1 * t_val1;

        t_val2 = ((nptr[0] - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t_val2 * t_val2;

        // Second element (one before)
        t_val1 = ((nptr[-1] - nptr[ns - 1]) << 2) + nptr[(ns << 1) - 1] - nptr[-ns - 1];
        pdif += t_val1 * t_val1;

        t_val2 = ((nptr[-1] - optr[os - 1]) << 2) + nptr[(ns << 1) - 1] - optr[-os - 1];
        tdif += t_val2 * t_val2;
    }

    // Handle remaining element if w is odd
    if ((w % 2) && nptr >= nptr) {  // Ensure not overstepped
        int t_val = ((nptr[0] - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t_val * t_val;

        t_val = ((nptr[0] - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t_val * t_val;
    }
}
