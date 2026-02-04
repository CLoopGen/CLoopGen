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
    // Variant 1: Increased computational intensity with unrolled operations and doubled effective trip count via stride reduction
    int64_t local_bdif = 0, local_tdif = 0;
    uint16_t *nend = nptr + w - 1;  // Adjust to allow safe access of [ns] and [ns<<1]
    
    for (rend = nend; nptr < rend; nptr += 2, optr += 2) {
        int t1, t2;

        // First iteration of unrolled loop
        t1 = ((nptr[0] - optr[os]) << 2) + nptr[(ns) << 1] - optr[-(os)];
        t2 = ((optr[0] - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-(ns)];
        local_bdif += t1 * t1;
        local_tdif += t2 * t2;

        // Second iteration of unrolled loop
        t1 = ((nptr[1] - optr[1 + os]) << 2) + (nptr[1 + (ns << 1)]) - optr[1 - os];
        t2 = ((optr[1] - nptr[1 + ns]) << 2) + (optr[1 + (os << 1)]) - nptr[1 - ns];
        local_bdif += t1 * t1;
        local_tdif += t2 * t2;
    }

    // Handle leftover element if w is odd
    if (nptr < rend + 1) {
        t = ((nptr[0] - optr[os]) << 2) + nptr[(ns) << 1] - optr[-(os)];
        local_bdif += t * t;
        t = ((optr[0] - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-(ns)];
        local_tdif += t * t;
    }

    bdif += local_bdif;
    tdif += local_tdif;
}
