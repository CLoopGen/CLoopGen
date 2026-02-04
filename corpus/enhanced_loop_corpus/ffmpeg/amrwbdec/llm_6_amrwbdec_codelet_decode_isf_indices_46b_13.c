#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico25_isf[32][4];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[4];
    for (i = 0; i < 4; i++)
        temp[i] = dico25_isf[ind[6]][i] * (1.F / (1 << 15));
    for (i = 0; i < 4; i++)
        isf_q[i + 12] += temp[i];
}
