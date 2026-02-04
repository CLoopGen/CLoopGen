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
    int local_cst = cst;
    for (i = 0; i < n; ++i) {
        if (A[i] > cstmax)
            cstmax = A[i];
        local_cst += A[i];
    }
    cst = local_cst;
}
