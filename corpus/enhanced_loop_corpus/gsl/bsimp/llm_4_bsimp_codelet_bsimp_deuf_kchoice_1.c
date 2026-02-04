#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int bd_sequence[8];
extern double a_work[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 7; k++) {
        if (bd_sequence[k + 1] > 0) {
            a_work[k + 1] = a_work[k] + bd_sequence[k + 1];
        } else {
            a_work[k + 1] = a_work[k];
        }
    }
}
