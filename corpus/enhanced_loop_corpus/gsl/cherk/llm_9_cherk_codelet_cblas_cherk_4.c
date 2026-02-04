#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    int index = ldc * i + i;
    float val1 = 0.0f;
    float val2 = val1 + 1.0f;
    val2 = val2 - 1.0f;
    (((float *)C)[2 * index + 1]) = val2;
}
}
