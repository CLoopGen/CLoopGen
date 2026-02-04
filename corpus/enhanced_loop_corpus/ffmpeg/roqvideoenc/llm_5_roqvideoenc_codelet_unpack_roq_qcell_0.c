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
        int skip_phase = (cp % 2 == 0);
        for (i = 0; i < 4; i++) {
            if (skip_phase && (qcell->idx[i] & 1)) continue;  // Skip odd indices in even cp phases
            int dst_base = 4 * 4 * cp + offsets[i];
            int src_base = qcell->idx[i] * 12 + 4 * cp;
            u[dst_base]         = cb2[src_base];
            u[dst_base + 1]     = cb2[src_base + 1];
            u[dst_base + 4]     = cb2[src_base + 2];
            u[dst_base + 5]     = cb2[src_base + 3];
        }
    }
}
