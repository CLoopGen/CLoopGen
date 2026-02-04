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
    // Variant 2: Strided Memory Access with Increased Stride
    // Introduce a strided access pattern (stride of 2) to reduce memory pressure and alter data reuse.
    // This variant processes every second element forward, then handles the odd segment if needed,
    // but here we assume w is even for simplicity and focus on stride-2 traversal.
    int i;
    for (i = 0; i < w; i += 2) {
        // Stride-2 access: process current and next-to-current in a staggered way
        bdif += ((t) = (((nptr[i]) - optr[i + os]) << 2) + nptr[i + (ns << 1)] - optr[i - os], (t) * (t));
        tdif += ((t) = (((optr[i]) - nptr[i + ns]) << 2) + optr[i + (os << 1)] - nptr[i - ns], (t) * (t));

        // Optional secondary accumulation with offset stride (simulates irregular access)
        if (i + 1 < w) {
            bdif += ((t) = (((nptr[i+1]) - optr[i+1 + os]) << 2) + nptr[i+1 + (ns << 1)] - optr[i+1 - os], (t) * (t));
            tdif += ((t) = (((optr[i+1]) - nptr[i+1 + ns]) << 2) + optr[i+1 + (os << 1)] - nptr[i+1 - ns], (t) * (t));
        }
    }
}
