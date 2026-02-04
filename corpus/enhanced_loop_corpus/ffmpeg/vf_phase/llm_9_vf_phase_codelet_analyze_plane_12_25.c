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
uint16_t *nend = nptr + (w & ~7);  // Align to multiple of 8 for unrolling
for (rend = nend; nptr < rend; nptr += 8, optr += 8) {
    #pragma unroll 8
    for (int i = 0; i < 8; i++) {
        int t1 = ((nptr[i]) - nptr[i + ns]) << 2;
        int t2 = nptr[i + (ns << 1)] - nptr[i - ns];
        pdif += (t1 + t2) * (t1 + t2);

        int t3 = ((optr[i]) - nptr[i + ns]) << 2;
        int t4 = optr[i + (os << 1)] - nptr[i - ns];
        tdif += (t3 + t4) * (t3 + t4);
    }
}
// Handle remaining elements
for (; nptr < rend + (w % 8); nptr++, optr++) {
    pdif += (((*nptr - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns]);
    tdif += (((*optr - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns]);
}
}
