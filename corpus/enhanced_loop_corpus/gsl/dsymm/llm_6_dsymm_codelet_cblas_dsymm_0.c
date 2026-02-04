#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n1; i++) {
        double temp = 0.0;
        for (j = 0; j < n2; j++) {
            temp += 1.0; // Introduce temporary accumulation (local RAW dependency)
            C[ldc * i + j] = temp; // WAW dependency removed by using temp; each write is now independent per j
        }
    }
}
