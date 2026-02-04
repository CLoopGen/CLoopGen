#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double a_work[8];
extern double alpha[7][7];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = a_work[1] * alpha[0][1];
    for (k = 0; k < 7 - 1; k++) {
        if (k + 2 < 8 && a_work[k + 2] > temp) {
            break;
        }
        temp = a_work[k + 1] * alpha[k][k + 1]; // Move dependency inside loop, creating WAW on temp
    }
}
