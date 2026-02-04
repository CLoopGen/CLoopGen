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
    for (i = 0; i < 4; i++) {
        int idx_val = qcell->idx[i];
        int cb2_base = idx_val * 12;
        for (cp = 0; cp < 3; cp++) {
            int u_base = 16 * cp + offsets[i];
            int cb2_offset = cb2_base + 4 * cp;
            u[u_base] = cb2[cb2_offset];
            u[u_base + 1] = cb2[cb2_offset + 1];
            u[u_base + 4] = cb2[cb2_offset + 2];
            u[u_base + 5] = cb2[cb2_offset + 3];
        }
    }
}
