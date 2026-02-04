#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lspf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant processes every second element in two passes to cover all indices
    for (i = 2; i < 10; i += 2)
        lspf[i] = (lspf[i] > lspf[i - 2] + 0.02) ? lspf[i] : (lspf[i - 2] + 0.02);
    for (i = 1; i < 10; i += 2)
        lspf[i] = (lspf[i] > lspf[i - 1] + 0.02) ? lspf[i] : (lspf[i - 1] + 0.02);
}
