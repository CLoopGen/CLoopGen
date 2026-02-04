#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern unsigned char *pd;
extern int i;
extern int l;
extern uint16_t run_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_buffer[8];
    int chunk_size = (l + 7) / 8;
    for (i = 0; i < l; i++) {
        int idx = i % 8;
        local_buffer[idx] = run_val; // Eliminate direct memory dependency; use local register file
        if ((i + 1) % chunk_size == 0 || i == l - 1) {
            // Flush buffer every chunk_size iterations to maintain approximate order
            for (int j = 0; j < 8 && (j * chunk_size + (i % chunk_size)) < l; j++) {
                ((((union unaligned_16 *)(pd + 2*(j * chunk_size + (i % chunk_size))))->l) = local_buffer[j]);
            }
        }
        // Break loop-carried dependency by decoupling computation from immediate store
    }
    // Note: This variant simulates software pipelining effect with delayed stores, removing immediate RAW/WAR dependencies across iterations
}
