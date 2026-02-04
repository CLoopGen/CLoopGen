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
    // Variant 2: Strided memory access with increased stride
    // Access every 4th element first, then proceed in phases
    // This changes spatial locality and may help in cache blocking scenarios
    const int stride = 4;
    int phase;

    for (phase = 0; phase < stride; phase++) {
        uint16_t *nstart = nptr + phase;
        uint16_t *ostart = optr + phase;
        uint16_t *nlimit = nptr + w - (stride - 1); // Ensure we don't go out of bounds

        if (nstart >= nlimit) continue;

        for (; nstart < nlimit; nstart += stride, ostart += stride) {
            // Use strided neighbors: ns and os replaced by fixed offset 4
            int idx_ns = stride;
            int idx_os = stride;

            t = ((*nstart - nstart[idx_ns]) << 2) + nstart[2*idx_ns] - nstart[-idx_ns];
            pdif += t * t;

            t = ((*nstart - ostart[idx_os]) << 2) + nstart[2*idx_ns] - ostart[-idx_os];
            bdif += t * t;

            t = ((*ostart - nstart[idx_ns]) << 2) + ostart[2*idx_os] - nstart[-idx_ns];
            tdif += t * t;
        }
    }

    // Final pass: complete any leftover elements with original logic
    // Re-synchronize nptr and optr to end position
    rend = nptr + w;
    for (; nptr < rend; nptr++, optr++) {
        t = ((*nptr - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t * t;

        t = ((*nptr - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        bdif += t * t;

        t = ((*optr - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];
        tdif += t * t;
    }
}
