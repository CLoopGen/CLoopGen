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
    // Variant 2: Strided memory access with stride = 4
    // Instead of processing elements consecutively, we jump by a fixed stride.
    // We process every 4th element in a round-robin fashion over 4 passes.

    const int stride = 4;
    uint16_t *nptr_base = nptr;
    uint16_t *optr_base = optr;

    for (int phase = 0; phase < stride; phase++) {
        uint16_t *nptr_phase = nptr_base + phase;
        uint16_t *optr_phase = optr_base + phase;
        uint16_t *rend_phase = nptr_phase + ((w - phase + stride - 1) / stride) * stride;

        for (; nptr_phase < rend_phase; nptr_phase += stride, optr_phase += stride) {
            if (nptr_phase >= nptr_base + w) break;

            int t_n = ((*nptr_phase - nptr_phase[ns]) << 2) + nptr_phase[(ns) << 1] - nptr_phase[-ns];
            pdif += t_n * t_n;

            int t_o = ((*nptr_phase - optr_phase[os]) << 2) + nptr_phase[(ns) << 1] - optr_phase[-os];
            tdif += t_o * t_o;

            int t_b = ((*optr_phase - nptr_phase[ns]) << 2) + optr_phase[(os) << 1] - nptr_phase[-ns];
            bdif += t_b * t_b;
        }
    }

    // Restore original pointers if needed by caller (optional, depending on usage context)
    // Note: Original function modifies nptr/optr, so we update them here to reflect full traversal.
    nptr = nptr_base + w;
    optr = optr_base + w;
}
