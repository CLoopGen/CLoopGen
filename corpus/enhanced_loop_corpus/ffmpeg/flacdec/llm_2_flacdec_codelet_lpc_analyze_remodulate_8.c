#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *decoded;
extern  int coeffs[32];
extern int order;
extern int qlevel;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = order; i < len; i++, decoded++) {
        int32_t p = 0;
        // Modified memory access: Strided access with stride of 2, wrapping if needed
        for (j = 0; j < order; j += 2) {
            int idx = j % order;
            p += coeffs[idx] * (uint32_t)decoded[idx];
            // Handle odd order by ensuring we don't skip last element
            if (j + 1 < order) {
                int idx_next = (j + 1) % order;
                p += coeffs[idx_next] * (uint32_t)decoded[idx_next];
            }
        }
        decoded[order] = (p >> qlevel);
    }
}
