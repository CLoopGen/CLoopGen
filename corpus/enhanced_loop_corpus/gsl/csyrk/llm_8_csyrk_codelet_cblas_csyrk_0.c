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
    for (j = 0; j < N; j++) {
        int idx = 2 * (ldc * i + j);
        ((float *)C)[idx] = 0.0;
        ((float *)C)[idx + 1] = 0.0;
    }
}
}
