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
    int limit_i = (i + 1 < n1) ? i + 2 : i + 1;
    for (j = 0; j < n2; j++) {
        int base_index1 = 2 * (ldc * i + j);
        ((double *)C)[base_index1] = 0.;
        ((double *)C)[base_index1 + 1] = 0.;
        if (i + 1 < n1) {
            int base_index2 = 2 * (ldc * (i + 1) + j);
            ((double *)C)[base_index2] = 0.;
            ((double *)C)[base_index2 + 1] = 0.;
        }
    }
}
}
