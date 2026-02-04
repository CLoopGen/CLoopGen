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
int temp_sum = 0;
int temp_max = (n > 0) ? A[0] : 0;
for (i = 0; i < n; ++i) {
    temp_sum += A[i];
    if (A[i] > temp_max)
        temp_max = A[i];
}
cst += temp_sum;
if (temp_max > cstmax)
    cstmax = temp_max;
}
