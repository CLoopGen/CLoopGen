#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int *A;
extern int i;
extern int cst;
extern int cstmax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; ++i) {
        if (!(A[i] <= 0)) {
            cst += A[i];
        }
        if (A[i] > cstmax && A[i] >= 0) {
            cstmax = A[i];
        }
    }
}
