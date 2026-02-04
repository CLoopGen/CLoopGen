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
    // Variant 2: Consecutive sequential access using local pointers with unrolling factor of 2
    uint16_t *nptr_local = nptr;
    uint16_t *optr_local = optr;
    rend = nptr_local + (w & ~1);  // Align to even boundary for unrolling

    for (; nptr_local < rend; nptr_local += 2, optr_local += 2) {
        // First element in pair
        pdif += ((t) = ((nptr_local[0] - nptr_local[ns]) << 2) + nptr_local[(ns) << 1] - nptr_local[-(ns)], (t) * (t));
        tdif += ((t) = ((optr_local[0] - nptr_local[ns]) << 2) + optr_local[(os) << 1] - nptr_local[-(ns)], (t) * (t));

        // Second element in pair
        pdif += ((t) = ((nptr_local[1] - nptr_local[1 + ns]) << 2) + nptr_local[1 + (ns) << 1] - nptr_local[1 - (ns)], (t) * (t));
        tdif += ((t) = ((optr_local[1] - nptr_local[1 + ns]) << 2) + optr_local[1 + (os) << 1] - nptr_local[1 - (ns)], (t) * (t));
    }

    // Handle leftover element if w is odd
    if ((w % 2) && nptr_local < nptr + w) {
        pdif += ((t) = ((*(nptr_local) - (nptr_local)[ns]) << 2) + (nptr_local)[(ns) << 1] - (nptr_local)[-(ns)], (t) * (t));
        tdif += ((t) = ((*(optr_local) - (nptr_local)[ns]) << 2) + (optr_local)[(os) << 1] - (nptr_local)[-(ns)], (t) * (t));
    }

    // Update global pointers if needed (assuming side effects are desired)
    nptr = nptr_local;
    optr = optr_local;
}
