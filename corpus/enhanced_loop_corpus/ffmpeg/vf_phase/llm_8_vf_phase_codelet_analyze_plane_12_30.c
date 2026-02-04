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
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled operations
    // Trip count reduced by processing 2 elements per iteration (loop unrolling with partial redundancy)
    int64_t local_pdif = 0, local_tdif = 0, local_bdif = 0;
    uint16_t *nend = nptr + w - (w % 2);  // Align to even boundary for unrolling

    for (rend = nend; nptr < rend; nptr += 2, optr += 2) {
        int t1, t2;

        // First element
        t1 = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        t2 = ((*(optr) - optr[os]) << 2) + optr[(os) << 1] - optr[-os];
        local_pdif += t1 * t1;
        local_tdif += (((*nptr - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os]) * 
                      (((*nptr - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os]);
        local_bdif += (((*optr - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns]) * 
                      (((*optr - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns]);

        // Second element (offset by 1)
        t1 = ((nptr[1] - nptr[1 + ns]) << 2) + nptr[1 + (ns << 1)] - nptr[1 - ns];
        t2 = ((optr[1] - optr[1 + os]) << 2) + optr[1 + (os << 1)] - optr[1 - os];
        local_pdif += t1 * t1;
        local_tdif += (((nptr[1] - optr[1 + os]) << 2) + nptr[1 + (ns << 1)] - optr[1 - os]) * 
                      (((nptr[1] - optr[1 + os]) << 2) + nptr[1 + (ns << 1)] - optr[1 - os]);
        local_bdif += (((optr[1] - nptr[1 + ns]) << 2) + optr[1 + (os << 1)] - nptr[1 - ns]) * 
                      (((optr[1] - nptr[1 + ns]) << 2) + optr[1 + (os << 1)] - nptr[1 - ns]);
    }

    // Handle leftover element if w is odd
    if (w % 2) {
        t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        local_pdif += t * t;
        t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        local_tdif += t * t;
        t = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];
        local_bdif += t * t;
        nptr++; optr++;
    }

    pdif += local_pdif;
    tdif += local_tdif;
    bdif += local_bdif;
}
