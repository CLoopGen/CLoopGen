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
        temp = lspf[i - 1] + 0.02;
        if (lspf[i] <= temp)
            lspf[i] = temp;
    }
}
