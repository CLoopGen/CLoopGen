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
    for (cp = 0; cp < 6; cp++) {
        int base_offset = 4 * 4 * (cp % 3);
        int src_base = qcell->idx[cp % 4] * 2 * 2 * 3 + 4 * (cp % 3);
        u[base_offset + offsets[cp % 4]] = cb2[src_base];
        u[base_offset + offsets[cp % 4] + 1] = cb2[src_base + 1];
        if (cp >= 2) {
            u[base_offset + offsets[cp % 4] + 4] = cb2[src_base + 2];
            u[base_offset + offsets[cp % 4] + 5] = cb2[src_base + 3];
        }
    }
}
