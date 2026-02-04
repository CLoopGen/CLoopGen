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
        int index = 2 * (ldc * i + j);
        ((float *)C)[index] = 0.0;
        ((float *)C)[index + 1] = 0.0;
        ((float *)C)[index + 2] = 0.0;
        ((float *)C)[index + 3] = 0.0;
    }
}
}
