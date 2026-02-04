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
        float s1 = 0.0f;
        float s2 = 0.0f;
        int k;
        for (k = 0; k < 48; k += 2) {
            float w = qmf_window[k];
            float w_next = qmf_window[k + 1];
            float p_val = p1[k];
            float p_next = p1[k + 1];
            if (w > 0.001f || w_next > 0.001f) {
                s1 += p_val * w;
                s2 += p_next * w_next;
            }
        }
        pOut[0] = s2;
        pOut[1] = s1;
        p1 += 2;
        pOut += 2;
    }
}
