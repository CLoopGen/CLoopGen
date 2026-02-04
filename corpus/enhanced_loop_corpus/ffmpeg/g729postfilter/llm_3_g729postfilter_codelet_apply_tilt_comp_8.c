#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int16_t *res_pst;
extern int subframe_size;
extern int tmp2;
extern int i;
extern int gt;
extern int ga;
extern int fact;
extern int sh_fact;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2, wrapping within bounds using modulo-like logic)
    // Simulate strided pattern by accessing every second element in reverse, with wraparound handling
    for (i = (subframe_size - 1) / 2; i >= 1; i--) {
        int idx = (subframe_size - 1) - (i * 2); // Reverse strided index
        if (idx < 1) continue; // Skip invalid indices to maintain correctness
        tmp2 = (gt * res_pst[idx - 1]) * 2 + 16384;
        tmp2 = res_pst[idx] + (tmp2 >> 15);
        tmp2 = (tmp2 * ga + fact) >> sh_fact;
        out[idx] = tmp2;
    }
    // Fill remaining positions with a forward strided pass to maintain coverage and realism
    for (i = (subframe_size - 2); i >= 1; i -= 2) {
        tmp2 = (gt * res_pst[i - 1]) * 2 + 16384;
        tmp2 = res_pst[i] + (tmp2 >> 15);
        tmp2 = (tmp2 * ga + fact) >> sh_fact;
        out[i] = tmp2;
    }
}
