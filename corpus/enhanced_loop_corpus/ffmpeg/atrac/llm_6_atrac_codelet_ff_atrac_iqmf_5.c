#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float qmf_window[48];
extern unsigned int nIn;
extern float *pOut;
extern int i;
extern int j;
extern float *p1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = nIn; j != 0; j--) {
        float s1 = 0.;
        float s2 = 0.;
        float temp1, temp2;
        for (i = 0; i < 48; i += 2) {
            temp1 = p1[i] * qmf_window[i];
            temp2 = p1[i + 1] * qmf_window[i + 1];
            s1 += temp1;
            s2 += temp2;
        }
        pOut[1] = s1;
        pOut[0] = s2;
        p1 += 2;
        pOut += 2;
    }
}
