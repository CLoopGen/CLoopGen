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
    int limit = (i + 1 < n1) ? n2 : n2;
    for (j = 0; j < limit; j++) {
        int index1 = 2 * (ldc * i + j);
        ((float *)C)[index1] = 0.;
        ((float *)C)[index1 + 1] = 0.;
        if (i + 1 < n1) {
            int index2 = 2 * (ldc * (i + 1) + j);
            ((float *)C)[index2] = 0.;
            ((float *)C)[index2 + 1] = 0.;
        }
    }
}
}
