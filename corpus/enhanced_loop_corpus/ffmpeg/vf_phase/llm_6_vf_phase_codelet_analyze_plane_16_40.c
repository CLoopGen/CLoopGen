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
    uint16_t *nptr_local = nptr;
    uint16_t *optr_local = optr;
    int64_t pdif_local = 0;
    int64_t tdif_local = 0;
    uint16_t *rend_local = nptr_local + w;

    for (; nptr_local < rend_local; nptr_local++, optr_local++) {
        int t1, t2;
        // Introduce temporary variables to break direct accumulation dependency (WAW and RAW on pdif/tdif)
        // This removes loop-carried dependencies on global accumulators
        t1 = ((*(nptr_local) - nptr_local[ns]) << 2) + nptr_local[(ns) << 1] - nptr_local[-ns];
        pdif_local += t1 * t1;

        t2 = ((*(nptr_local) - optr_local[os]) << 2) + nptr_local[(ns) << 1] - optr_local[-os];
        tdif_local += t2 * t2;
    }
    // Update global variables only once after loop
    pdif += pdif_local;
    tdif += tdif_local;
    nptr = nptr_local;
    optr = optr_local;
}
