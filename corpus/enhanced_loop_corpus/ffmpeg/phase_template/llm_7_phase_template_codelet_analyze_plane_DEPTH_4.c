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
    uint16_t *rend_end = nptr + w;
    int64_t temp_diff_accum = 0;
    int t_val;

    // Introduce loop-carried dependency via temp_diff_accum and sequential update pattern
    for (; nptr < rend_end; nptr += 2, optr += 2) {
        // Process two iterations with partial reuse and staggered access to create new RAW/WAR patterns
        if (nptr + 1 >= rend_end) break;

        // First pair: introduce dependency on previous temp_diff_accum
        t_val = ((nptr[0] - optr[os]) << 2) + nptr[(ns) << 1] - optr[-(os)];
        temp_diff_accum += (int64_t)(t_val * t_val) + temp_diff_accum; // Loop-carried dependence

        t_val = ((optr[0] - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-(ns)];
        temp_diff_accum += (int64_t)(t_val * t_val);

        // Second element in unrolled pair — creates WAW and RAW vs. first
        t_val = ((nptr[1] - optr[1 + os]) << 2) + (nptr[1 + (ns << 1)]) - optr[1 - os];
        temp_diff_accum += (int64_t)(t_val * t_val);

        t_val = ((optr[1] - nptr[1 + ns]) << 2) + optr[1 + (os << 1)] - nptr[1 - ns];
        temp_diff_accum += (int64_t)(t_val * t_val);
    }

    // Final reduction into shared globals with a single write to minimize interference
    tdif += temp_diff_accum;
    bdif += temp_diff_accum;
}
