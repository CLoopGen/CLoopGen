#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int bd_sequence[8];
extern double a_work[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[8];
    temp[0] = a_work[0];
    for (k = 0; k < 7; k++) {
        temp[k + 1] = temp[k] + bd_sequence[k + 1];
    }
    for (k = 0; k < 8; k++) {
        a_work[k] = temp[k];
    }
}
