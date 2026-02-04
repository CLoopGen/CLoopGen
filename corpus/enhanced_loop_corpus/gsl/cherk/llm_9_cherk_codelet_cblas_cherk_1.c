#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    if (i < N) {
        for (j = 0; j <= i; j++) {
            int idx1 = 2 * (ldc * i + j);
            int idx2 = 2 * (ldc * (i + 1) + j);
            ((float *)C)[idx1] = 0.;
            ((float *)C)[idx1 + 1] = 0.;
            if (i + 1 < N) {
                ((float *)C)[idx2] = 0.;
                ((float *)C)[idx2 + 1] = 0.;
            }
        }
    }
}
}
