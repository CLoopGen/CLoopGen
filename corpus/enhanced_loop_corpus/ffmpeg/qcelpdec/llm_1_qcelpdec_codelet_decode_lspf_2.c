#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lspf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 9; i > 0; i--) {
        float temp = lspf[i] - 0.02;
        if (lspf[i - 1] > temp)
            lspf[i - 1] = temp;
    }
}
