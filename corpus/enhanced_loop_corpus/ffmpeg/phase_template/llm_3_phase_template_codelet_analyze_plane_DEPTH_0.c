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
    // Variant 2: Consecutive forward traversal using pointer arithmetic with local accumulation
    uint16_t *nptr_end = nptr + w;
    int ns2 = ns << 1;
    int os2 = os << 1;
    int64_t local_pdif = 0, local_tdif = 0;

    for (; nptr < nptr_end; nptr++, optr++) {
        int t1 = ((*nptr - nptr[ns]) << 2) + nptr[ns2] - nptr[-ns];
        int t2 = ((*nptr - optr[os]) << 2) + nptr[ns2] - optr[-os];
        local_pdif += t1 * t1;
        local_tdif += t2 * t2;
    }
    pdif += local_pdif;
    tdif += local_tdif;
}
