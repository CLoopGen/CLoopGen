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
        int temp_offsets[4];
        for (i = 0; i < 4; i++) {
            temp_offsets[i] = offsets[i] + 16 * cp;
        }
        for (i = 0; i < 4; i++) {
            int src_idx = qcell->idx[i] * 12 + 4 * cp;
            u[temp_offsets[i]]      = cb2[src_idx];
            u[temp_offsets[i] + 1]  = cb2[src_idx + 1];
            u[temp_offsets[i] + 4]  = cb2[src_idx + 2];
            u[temp_offsets[i] + 5]  = cb2[src_idx + 3];
        }
    }
}
