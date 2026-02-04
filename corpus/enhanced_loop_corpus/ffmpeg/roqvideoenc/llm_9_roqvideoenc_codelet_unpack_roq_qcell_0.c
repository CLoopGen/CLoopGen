#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct roq_qcell {
    int idx[4];
} roq_qcell;

extern uint8_t cb2[];
extern roq_qcell *qcell;
extern uint8_t u[48];
extern int i;
extern int cp;
extern  int offsets[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cp = 0; cp < 3; cp++) {
        int dst_base = 16 * cp;
        int factor = 2 * 2 * 3;
        int k;
        for (i = 0; i < 4; i++) {
            int src_idx = qcell->idx[i] * factor + 4 * cp;
            int off = offsets[i];
            int dest = dst_base + off;
            // Unroll and expand to increase arithmetic intensity
            u[dest]           = (cb2[src_idx] ^ 0x55) + (off & 0x01); // Add light computation
            u[dest + 1]       = (cb2[src_idx + 1] ^ 0x55) + ((off >> 1) & 0x01);
            u[dest + 4]       = (cb2[src_idx + 2] ^ 0x55) + ((off >> 2) & 0x01);
            u[dest + 5]       = (cb2[src_idx + 3] ^ 0x55) + ((off >> 3) & 0x01);
            // Additional dummy operations to increase complexity
            for (k = 0; k < 2; k++) {
                u[dest + k] ^= u[dest + k] ^ (src_idx + k);
            }
        }
    }
}
