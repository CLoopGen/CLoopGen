#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int bd_sequence[8];
extern double a_work[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 3; k++) {
    for (int j = 0; j < 2; j++) {
        if (k < 6 || j == 0) {
            a_work[k * 2 + j + 1] = a_work[k * 2 + j] + bd_sequence[k * 2 + j + 1];
        }
    }
}
}
