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
    if (i % 2 == 0) {
        for (j = 0; j < n2; j++) {
            (((float *)C)[2 * (ldc * i + j)]) = 0.;
            (((float *)C)[2 * (ldc * i + j) + 1]) = 0.;
        }
    } else {
        for (j = n2 - 1; j >= 0; j--) {
            (((float *)C)[2 * (ldc * i + j)]) = 0.;
            (((float *)C)[2 * (ldc * i + j) + 1]) = 0.;
        }
    }
}
}
