#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx;
    float prev = 0.0f;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            idx = ldc * i + j;
            C[idx] = prev;       // Introduce RAW dependency: current value depends on previous iteration
            prev = C[idx] + 1.0f; // Introduce WAW and WAR: write after write and write after read via 'prev'
        }
    }
}
