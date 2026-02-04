#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int *A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n * 3; ++i) {
        int idx = i % n;
        A[idx] = A[idx] * 2 + 50000;
    }
}
