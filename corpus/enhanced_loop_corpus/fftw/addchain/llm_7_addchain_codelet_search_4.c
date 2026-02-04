#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ldcost;
extern int t;
extern int *A;
extern int *B;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= t; ++i) {
        if (i > 1) {
            A[B[-i]] = A[B[-(i-1)]]; // Introduce RAW dependency: current write depends on previous read
        } else {
            A[B[-i]] = ldcost;
        }
    }
}
