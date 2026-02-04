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
int j;
for (j = 0; j < 1; ++j) {
    for (i = 0; i < n; ++i) {
        cst += A[i];
        if (A[i] > cstmax)
            cstmax = A[i];
    }
}
}
