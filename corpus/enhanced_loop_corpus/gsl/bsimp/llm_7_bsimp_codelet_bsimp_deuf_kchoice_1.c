#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int bd_sequence[8];
extern double a_work[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[8] = {0};
    temp[0] = a_work[0];
    for (k = 1; k <= 7; k++) {
        temp[k] = temp[k - 1] + bd_sequence[k];
    }
    for (k = 0; k < 7; k++) {
        a_work[k + 1] = temp[k + 1];
    }
}
