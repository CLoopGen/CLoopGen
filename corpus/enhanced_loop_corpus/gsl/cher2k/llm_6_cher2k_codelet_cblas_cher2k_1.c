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
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            int idx = 2 * (ldc * i + j);
            ((float *)C)[idx] = 0.;
            ((float *)C)[idx + 1] = 0.;
            // Introduce artificial dependency: current iteration depends on previous j
            if (j > 0) {
                ((float *)C)[idx] += ((float *)C)[idx - 2]; // RAW dependency across j iterations
            }
        }
    }
}
