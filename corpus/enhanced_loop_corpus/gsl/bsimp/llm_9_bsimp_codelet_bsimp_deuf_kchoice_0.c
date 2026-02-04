#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int bd_sequence[8];
extern double a_work[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 14; k += 2) {
    a_work[k / 2 + 1] = a_work[k / 2] + bd_sequence[k / 2 + 1];
    a_work[k / 2 + 1] *= 1.5;
}
}
