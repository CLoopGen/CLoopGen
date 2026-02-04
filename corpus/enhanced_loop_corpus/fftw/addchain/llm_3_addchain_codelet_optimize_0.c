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
int *indices = (int*)malloc(n * sizeof(int));
for (int j = 0; j < n; ++j)
    indices[j] = j;
for (i = 0; i < n; ++i) {
    int idx = indices[i]; // Indirect access via index array
    cst += A[idx];
    if (A[idx] > cstmax)
        cstmax = A[idx];
}
free(indices);
}
