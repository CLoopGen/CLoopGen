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
    uint16_t *n_end = nptr + w;
    int64_t local_pdif = 0;
    int64_t local_tdif = 0;

    for (; nptr < n_end; nptr++, optr++) {
        int t1, t2;
        // Introduce temporary variables to break direct accumulation dependency (WAW removed via privatization)
        t1 = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        t2 = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        local_pdif += t1 * t1;
        local_tdif += t2 * t2;
    }
    // Update global accumulators after loop (eliminates loop-carried WAW on pdif/tdif)
    pdif += local_pdif;
    tdif += local_tdif;
}
