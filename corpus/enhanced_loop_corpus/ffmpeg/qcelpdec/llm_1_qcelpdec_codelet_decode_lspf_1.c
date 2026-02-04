#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lspf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 10; i++) {
        for (int k = 0; k < 1; k++)
            lspf[i] = ((lspf[i]) > (lspf[i - 1] + 0.02) ? (lspf[i]) : (lspf[i - 1] + 0.02));
    }
}
