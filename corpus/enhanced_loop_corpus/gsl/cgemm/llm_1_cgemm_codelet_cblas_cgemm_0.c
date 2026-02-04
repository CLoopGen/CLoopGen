#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int total_elements = n1 * n2;
for (int k = 0; k < total_elements; k++) {
    int i = k / n2;
    int j = k % n2;
    ((float *)C)[2 * (ldc * i + j)] = 0.;
    ((float *)C)[2 * (ldc * i + j) + 1] = 0.;
}
}
