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
    for (j = nIn; j > 0; --j) {
        float s1 = 0.f;
        float s2 = 0.f;
        for (i = 0; i < 48; i += 2) {
            s1 += p1[i] * qmf_window[i];
            s2 += p1[i + 1] * qmf_window[i + 1];
        }
        if (s1 >= 0.0f) {
            pOut[0] = s2;
            pOut[1] = s1;
        } else {
            pOut[0] = -s2;
            pOut[1] = -s1;
        }
        p1 += 2;
        pOut += 2;
    }
}
