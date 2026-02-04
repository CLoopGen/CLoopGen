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
for (i = 0; i < n1 * n2; i++) {
    int idx = 2 * i;
    ((float *)C)[idx] = 0.;
    ((float *)C)[idx + 1] = 0.;
}
}
