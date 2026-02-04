#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lspf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i > 0; i--) {
        float diff = lspf[i] - 0.02f;
        float adjusted = (lspf[i - 1] > diff) ? diff : lspf[i - 1];
        lspf[i - 1] = adjusted;
    }
}
