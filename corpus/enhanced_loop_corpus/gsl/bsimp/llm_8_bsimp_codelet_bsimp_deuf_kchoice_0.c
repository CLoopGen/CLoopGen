#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int bd_sequence[8];
extern double a_work[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (k = 0; k < 6; k++) {
    a_work[k + 2] = a_work[k] + bd_sequence[k + 1] + bd_sequence[k + 2];
}
}
