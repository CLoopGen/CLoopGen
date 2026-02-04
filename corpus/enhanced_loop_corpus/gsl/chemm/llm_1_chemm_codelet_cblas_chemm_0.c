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
for (i = 0; i < n1; i += 2) {
    int i1 = i;
    int i2 = i + 1;
    for (j = 0; j < n2; j++) {
        // Process two rows at once (if within bounds)
        int index1 = ldc * i1 + j;
        (((float *)C)[2 * index1]) = 0.;
        (((float *)C)[2 * index1 + 1]) = 0.;

        if (i2 < n1) {
            int index2 = ldc * i2 + j;
            (((float *)C)[2 * index2]) = 0.;
            (((float *)C)[2 * index2 + 1]) = 0.;
        }
    }
}
}
