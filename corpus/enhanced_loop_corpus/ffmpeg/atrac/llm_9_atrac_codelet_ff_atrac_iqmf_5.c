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
    for (j = nIn / 2; j != 0; j--) {
        float s1_1 = 0., s2_1 = 0.;
        float s1_2 = 0., s2_2 = 0.;
        for (i = 0; i < 48; i += 2) {
            s1_1 += p1[i] * qmf_window[i];
            s2_1 += p1[i + 1] * qmf_window[i + 1];
            s1_2 += p1[i + 96] * qmf_window[i];
            s2_2 += p1[i + 97] * qmf_window[i + 1];
        }
        pOut[0] = s2_1;
        pOut[1] = s1_1;
        pOut[2] = s2_2;
        pOut[3] = s1_2;
        p1 += 4;
        pOut += 4;
    }
}
