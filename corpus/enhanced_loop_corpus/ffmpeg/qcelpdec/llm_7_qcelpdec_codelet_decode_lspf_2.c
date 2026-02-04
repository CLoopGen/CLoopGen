#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lspf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_val, current_lim;
    prev_val = lspf[8];
    for (i = 9; i > 1; i--) {
        current_lim = lspf[i] - 0.02;
        lspf[i - 1] = (prev_val > current_lim) ? current_lim : prev_val;
        prev_val = (lspf[i - 2] > current_lim) ? current_lim : lspf[i - 2];
    }
    // Handle last iteration separately to maintain semantic consistency
    current_lim = lspf[1] - 0.02;
    lspf[0] = (lspf[0] > current_lim) ? current_lim : lspf[0];
}
