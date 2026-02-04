#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern int i;
extern int i_max_corr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 16 - 1; i < 18 - 1; i += 2) {
        float temp1 = isf[i - 1];
        float temp2 = isf[i - 1 - i_max_corr];
        isf[i] = temp1 + temp2;
        if (i >= 2) {
            isf[i] -= isf[i - 2 - i_max_corr];
        }
    }
}
