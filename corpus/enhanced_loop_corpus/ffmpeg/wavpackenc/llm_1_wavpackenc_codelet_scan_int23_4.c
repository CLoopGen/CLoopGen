#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int nb_samples;
extern uint32_t magdata;
extern uint32_t ordata;
extern uint32_t xordata;
extern uint32_t anddata;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Outer loop splits the iteration space into chunks to increase nesting depth
    const int chunk_size = 16;
    int num_chunks = (nb_samples + chunk_size - 1) / chunk_size;

    for (int c = 0; c < num_chunks; c++) {
        int start = c * chunk_size;
        int end = (start + chunk_size > nb_samples) ? nb_samples : start + chunk_size;

        // Inner loop processes each sample in the chunk
        for (i = start; i < end; i++) {
            int32_t M = samples_l[i];
            magdata |= (M < 0) ? ~M : M;
            xordata |= M ^ -(M & 1);
            anddata &= M;
            ordata |= M;
            if ((ordata & 1) && !(anddata & 1) && (xordata & 2))
                return;
        }
    }
}
