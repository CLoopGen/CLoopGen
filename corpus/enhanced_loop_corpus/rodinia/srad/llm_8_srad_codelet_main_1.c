#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nc;
extern int *jE;
extern int *jW;
extern long j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j < Nc - 1; j += 2) {
    jW[j] = j - 1;
    jE[j] = j + 1;
    jW[j+1] = j;
    jE[j+1] = j + 2;
}
}
