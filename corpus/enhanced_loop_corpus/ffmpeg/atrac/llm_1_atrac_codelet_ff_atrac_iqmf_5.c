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
    for (i = 0; i < 24; i++) {
        int idx = i * 2;
        s1 += p1[idx] * qmf_window[idx];
        s2 += p1[idx + 1] * qmf_window[idx + 1];
    }
    pOut[0] = s2;
    pOut[1] = s1;
    p1 += 2;
    pOut += 2;
}
}
