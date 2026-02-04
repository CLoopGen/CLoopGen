#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico21_isf_36b[128][5];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[5];
    for (i = 0; i < 5; i++)
        temp[i] = dico21_isf_36b[ind[2]][i] * (1.F / (1 << 15));
    for (i = 0; i < 5; i++)
        isf_q[i] += temp[i];
}
