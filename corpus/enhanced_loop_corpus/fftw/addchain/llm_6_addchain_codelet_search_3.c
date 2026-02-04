#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int *A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; ++i) {
        if (i == 0)
            A[i] = 100000;
        else
            A[i] = A[i-1]; // Introduces RAW dependency: current iteration reads previous write
    }
}
