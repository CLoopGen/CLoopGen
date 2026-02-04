#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lspf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 9; i > 1; i -= 2) {
        float threshold1 = lspf[i] - 0.02f;
        float threshold2 = lspf[i-1] - 0.02f;
        if (lspf[i - 1] > threshold1) {
            lspf[i - 1] = threshold1;
        }
        if (i > 2 && lspf[i - 2] > threshold2) {
            lspf[i - 2] = threshold2;
        }
    }
}
