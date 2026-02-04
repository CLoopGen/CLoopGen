#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico23_isf_36b[64][7];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 0; i < 7; i++)
            isf_q[i + 9] += dico23_isf_36b[ind[4]][i] * (1.F / (1 << 15));
}
