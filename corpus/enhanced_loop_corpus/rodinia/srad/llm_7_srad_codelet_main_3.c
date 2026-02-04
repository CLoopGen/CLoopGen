#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long Nc;
extern int *jE;
extern int *jW;
extern long j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
long temp_jW, temp_jE;
for (j = 0; j < Nc; j++) {
    temp_jW = j - 1;      // Remove direct write to memory early
    temp_jE = j + 1;
    jW[j] = temp_jW;      // Eliminate potential WAW and WAR hazards by deferring stores
    jE[j] = temp_jE;
}
}
