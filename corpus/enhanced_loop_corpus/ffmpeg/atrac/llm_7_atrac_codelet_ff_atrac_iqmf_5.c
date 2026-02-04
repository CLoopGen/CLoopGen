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
        float acc[2] = {0.0f, 0.0f};
        for (i = 0; i < 48; i += 2) {
            acc[0] += p1[i] * qmf_window[i];
            acc[1] += p1[i + 1] * qmf_window[i + 1];
        }
        pOut[0] = acc[1];
        pOut[1] = acc[0];
        p1 += 2;
        pOut += 2;
    }
}
