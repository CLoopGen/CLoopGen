#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 20; i++) {
    isf[i] *= 0.80000000000000004;
    isf[i] += 0.1;
}
}
