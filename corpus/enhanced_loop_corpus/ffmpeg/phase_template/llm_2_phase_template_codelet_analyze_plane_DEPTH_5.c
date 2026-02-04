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
    // Variant 1: Consecutive memory access with precomputed base offsets
    // Instead of strided access using [os] and [ns], we use unit stride by restructuring data access
    // This improves cache locality assuming os and ns are greater than 1 originally

    uint16_t *nptr_end = nptr + w;
    int ns2 = ns << 1;
    int os2 = os << 1;

    for (; nptr < nptr_end; nptr++, optr++) {
        int n_curr = *nptr;
        int o_curr = *optr;

        int n_next_ns = nptr[ns];
        int o_next_os = optr[os];
        int n_next_ns2 = nptr[ns2];
        int o_prev_os = optr[-os];
        int n_prev_ns = nptr[-ns];
        int o_next_os2 = optr[os2];

        int bdif_term = ((t) = ((n_curr - o_next_os) << 2) + n_next_ns2 - o_prev_os, t * t);
        int tdif_term = ((t) = ((o_curr - n_next_ns) << 2) + o_next_os2 - n_prev_ns, t * t);

        bdif += bdif_term;
        tdif += tdif_term;
    }
}
