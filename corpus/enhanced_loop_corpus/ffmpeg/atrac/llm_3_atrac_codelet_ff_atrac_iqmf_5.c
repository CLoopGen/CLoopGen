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
        // Strided access with reversed loop order and alternating window indexing
        for (i = 46; i >= 0; i -= 2) {
            s1 += p1[i] * qmf_window[47 - i];
            s2 += p1[i + 1] * qmf_window[46 - i];
        }
        pOut[0] = s2;
        pOut[1] = s1;
        p1 += 2;
        pOut += 2;
    }
}
