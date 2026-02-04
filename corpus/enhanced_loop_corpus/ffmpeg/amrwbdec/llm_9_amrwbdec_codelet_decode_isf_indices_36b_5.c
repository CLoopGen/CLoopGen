#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico22_isf_36b[128][4];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float scale = 1.F / (1 << 15);
    const int16_t* base_row = dico22_isf_36b[ind[3]];
    isf_q[5] += base_row[0] * scale;
    isf_q[6] += base_row[1] * scale;
    isf_q[7] += base_row[2] * scale;
    isf_q[8] += base_row[3] * scale;
}
