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
    // Variant 2: Strided memory access with fixed stride (stride = 4)
    // Processes every 4th element in a strided pattern to simulate non-unit stride access,
    // which may occur in multi-dimensional array traversals or sub-sampling scenarios.

    const int stride = 4;
    uint16_t *base_n = nptr;
    uint16_t *base_o = optr;
    int effective_w = (w + stride - 1) / stride; // Number of iterations for strided access

    for (int i = 0; i < effective_w; i++) {
        uint16_t *curr_n = base_n + i * stride;
        uint16_t *curr_o = base_o + i * stride;

        // Ensure we don't go out of bounds
        if (curr_n >= base_n + w || curr_o >= base_o + w) break;

        t = ((*curr_n - curr_n[ns]) << 2) + curr_n[(ns) << 1] - curr_n[-ns];
        pdif += t * t;

        t = ((*curr_n - curr_o[os]) << 2) + curr_n[(ns) << 1] - curr_o[-os];
        tdif += t * t;
    }

    // Update global pointers to reflect forward progress (simulate side effect)
    nptr = base_n + w;
    optr = base_o + w;
}
