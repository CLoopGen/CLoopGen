#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flattened single loop variant simulating reduced nesting depth
int idx = 0;
for (idx = 0; idx < n1 * n2; idx++) {
    C[idx] = 0.;
}
}
