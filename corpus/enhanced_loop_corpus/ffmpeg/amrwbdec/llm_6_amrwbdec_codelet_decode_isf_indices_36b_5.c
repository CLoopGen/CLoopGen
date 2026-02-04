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
    float temp[4];
    for (i = 0; i < 4; i++)
        temp[i] = dico22_isf_36b[ind[3]][i] * (1.F / (1 << 15));
    for (i = 0; i < 4; i++)
        isf_q[i + 5] += temp[i];
}
