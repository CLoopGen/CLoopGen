#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t dico22_isf[128][3];
extern uint16_t *ind;
extern float *isf_q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        float val = dico22_isf[ind[3]][i] * (1.F / (1 << 15));
        isf_q[i + 3] = isf_q[i + 3] + val;
        isf_q[i] = isf_q[i] + val; // Introduces WAW and WAR dependency on isf_q, creates loop-carried dependence via reuse of val
    }
}
