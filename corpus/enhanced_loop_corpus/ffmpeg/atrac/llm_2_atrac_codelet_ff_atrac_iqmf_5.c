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



void loop() {
    for (j = nIn; j != 0; j--) {
        float s1 = 0.;
        float s2 = 0.;
        // Change memory access to consecutive pointer-based access with pre-increment offset
        float *p1_offset = p1;
        const float *win = qmf_window;
        for (i = 0; i < 48; i += 2) {
            s1 += p1_offset[i] * win[i];
            s2 += p1_offset[i + 1] * win[i + 1];
        }
        pOut[0] = s2;
        pOut[1] = s1;
        p1 += 2;
        pOut += 2;
    }
}
