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
    float temp = 0.0;
    for (i = 0; i < N; i++) {
        temp = C[ldc * i + i]; // Introduce dependency: each iteration reads previous write via temp
        for (j = i; j < N; j++) {
            temp += 1.0; // Create artificial dependency chain using temp
            C[ldc * i + j] = temp;
        }
    }
}
