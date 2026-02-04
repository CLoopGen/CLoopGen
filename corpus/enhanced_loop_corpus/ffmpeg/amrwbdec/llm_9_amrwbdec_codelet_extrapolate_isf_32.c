#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 10; i++) {
    isf[2*i] *= 0.80000000000000004;
    isf[2*i + 1] *= 0.80000000000000004;
    isf[2*i] = (isf[2*i] > 0.0) ? isf[2*i] : -isf[2*i];
}
}
