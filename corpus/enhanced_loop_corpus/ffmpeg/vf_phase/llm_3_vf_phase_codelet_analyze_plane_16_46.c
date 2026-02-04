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
    // Variant 2: Strided Access with Fixed Step Independent of ns/os
    // Use a fixed stride (e.g., 4) through the arrays to create regular but non-unit memory access pattern
    // This simulates processing every 4th element first, then shifting the start index (not full loop unroll)
    const int stride = 4;
    ptrdiff_t offset;
    for (int phase = 0; phase < stride; phase++) {
        uint16_t *start_n = nptr + phase;
        uint16_t *start_o = optr + phase;
        rend = nptr + w - stride + phase;  // Ensure we don't go out of bounds

        for (offset = 0; start_n + offset < rend; offset += stride) {
            uint16_t *cur_n = start_n + offset;
            uint16_t *cur_o = start_o + offset;

            t = ((*cur_n - cur_n[ns]) << 2) + cur_n[(ns) << 1] - cur_n[-ns];
            pdif += t * t;

            t = ((*cur_n - cur_o[os]) << 2) + cur_n[(ns) << 1] - cur_o[-os];
            tdif += t * t;

            t = ((*cur_o - cur_n[ns]) << 2) + cur_o[(os) << 1] - cur_n[-ns];
            bdif += t * t;
        }
    }
    // Final pass: update nptr and optr to reflect full traversal (semantic consistency)
    nptr += w;
    optr += w;
}
