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
    // Variant 1: Consecutive memory access with manual pointer arithmetic unrolled by factor of 2
    // This variant accesses nptr and optr in a consecutive manner, reducing stride by processing two elements at once
    // to improve cache locality and enable potential vectorization.

    uint16_t *nend = nptr + w;
    uint16_t *oend = optr + w;

    for (rend = nend; nptr < rend - 1; ) {
        // Process two elements consecutively
        int t1, t2;

        // First element
        pdif += (t1 = (((*nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns], t1 * t1);
        tdif += (t1 = (((*nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os], t1 * t1);
        bdif += (t1 = (((*optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns], t1 * t1);

        nptr++;
        optr++;

        // Second element
        pdif += (t2 = (((*nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns], t2 * t2);
        tdif += (t2 = (((*nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os], t2 * t2);
        bdif += (t2 = (((*optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns], t2 * t2);

        nptr++;
        optr++;
    }

    // Handle remaining element if width is odd
    if (nptr < rend) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)] , (t) * (t));
        tdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)] , (t) * (t));
        bdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)] , (t) * (t));
        nptr++;
        optr++;
    }
}
