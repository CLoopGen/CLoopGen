#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        float temp = 0.0;
        for (j = i; j < N; j++) {
            temp += C[ldc * i + j];
            C[ldc * i + j] = temp;
        }
    }
}
