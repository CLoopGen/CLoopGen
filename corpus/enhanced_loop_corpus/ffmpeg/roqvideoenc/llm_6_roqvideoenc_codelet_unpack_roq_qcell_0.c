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
    for (cp = 0; cp < 3; cp++)
        for (i = 0; i < 4; i++) {
            int base_src = qcell->idx[i] * 12 + 4 * cp;
            int base_dst = 16 * cp + offsets[i];
            u[base_dst]           = cb2[base_src];
            u[base_dst + 1]       = cb2[base_src + 1];
            u[base_dst + 4]       = cb2[base_src + 2];
            u[base_dst + 5]       = cb2[base_src + 3];
        }
}
