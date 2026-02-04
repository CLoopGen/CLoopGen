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
        for (i = 0; i < 4; i++) {
            int base_u = 4 * 4 * cp + offsets[i];
            int base_cb2 = qcell->idx[i] * 2 * 2 * 3 + 4 * cp;
            u[base_u] = cb2[base_cb2];
            u[base_u + 1] = cb2[base_cb2 + 1];
            u[base_u + 4] = cb2[base_cb2 + 2];
            u[base_u + 5] = cb2[base_cb2 + 3];
        }
    }
}
