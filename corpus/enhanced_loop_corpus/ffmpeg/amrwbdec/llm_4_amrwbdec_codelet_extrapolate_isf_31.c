#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 15, j = 0; i < 19; i++, j++) {
        if (j % 2 == 0) {
            isf[i] = isf[i - 1] + diff_isf[j] * (1.F / (1 << 15));
        } else {
            isf[i] = isf[i - 1];
        }
    }
}
