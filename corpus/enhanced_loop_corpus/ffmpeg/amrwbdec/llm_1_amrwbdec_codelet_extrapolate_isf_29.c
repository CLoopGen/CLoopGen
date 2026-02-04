#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern float scale;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 16 - 1; i < 20 - 1; i++) {
        for (j = 0; j < 1; j++) {
            diff_isf[j] = scale * (isf[i] - isf[i - 1]);
        }
    }
}
