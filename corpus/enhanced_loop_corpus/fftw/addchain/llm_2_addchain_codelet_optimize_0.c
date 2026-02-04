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
for (i = 0; i < n; i += 2) {
    cst += A[i];
    if (A[i] > cstmax)
        cstmax = A[i];
    if (i + 1 < n) {
        cst += A[i + 1];
        if (A[i + 1] > cstmax)
            cstmax = A[i + 1];
    }
}
}
