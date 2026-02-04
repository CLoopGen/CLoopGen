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
cst = 0;
cstmax = 0;
for (i = 0; i < n && i < 1000; ++i) {
    cst += A[i] * 2 + 1;
    cstmax = (A[i] > cstmax) ? A[i] : cstmax;
    A[i] = A[i] + 1;
}
}
