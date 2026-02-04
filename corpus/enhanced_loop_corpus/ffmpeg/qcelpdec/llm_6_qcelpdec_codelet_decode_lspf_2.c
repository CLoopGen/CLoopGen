#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lspf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (i = 1; i < 10; i++) {
        temp = lspf[i] - 0.02;
        lspf[i - 1] = (lspf[i - 1] > temp) ? temp : lspf[i - 1];
    }
}
