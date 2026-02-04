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
for (i = 0; i < n1; i++) {
    int base = ldc * i;
    for (j = 0; j < n2; j++) {
        int offset = 2 * (base + j);
        ((double *)C)[offset] = 0.;
        ((double *)C)[offset + 1] = 0.;
    }
}
}
