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
    // Variant 2: Consecutive Forward Access with Local Buffer Simulation
    // Simulate a more cache-friendly access pattern by accessing data consecutively
    // and using local variables to reduce redundant memory reads.
    // Assume ns and os are positive and valid for forward indexing.

    uint16_t *nbase = nptr;
    uint16_t *obase = optr;
    rend = nptr + w;

    for (int i = 0; nbase + i < rend; i++) {
        uint16_t curr_n = nbase[i];
        uint16_t next_n_ns = nbase[i + ns];
        uint16_t next_n_2ns = nbase[i + (ns << 1)];
        uint16_t prev_n_ns = (i >= ns) ? nbase[i - ns] : nbase[i]; // boundary clamp

        uint16_t curr_o = obase[i];
        uint16_t next_o_os = obase[i + os];
        uint16_t prev_o_os = (i >= os) ? obase[i - os] : obase[i]; // boundary clamp

        t = ((curr_n - next_n_ns) << 2) + next_n_2ns - prev_n_ns;
        pdif += t * t;

        t = ((curr_n - next_o_os) << 2) + next_n_2ns - prev_o_os;
        tdif += t * t;
    }

    // Update global pointers to reflect advancement (as original loop does)
    nptr = rend;
    optr += w;
}
