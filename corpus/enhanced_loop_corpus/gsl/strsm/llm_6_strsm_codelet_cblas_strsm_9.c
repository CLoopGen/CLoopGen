#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern float *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (i = 0; i < n1; i++) {
        temp = alpha; // Introduce temporary to modify data dependency flow
        for (j = 0; j < n2; j++) {
            temp = B[ldb * i + j] * temp; // Create intra-loop dependency: each iteration depends on previous temp (WAW-like chain)
            B[ldb * i + j] = temp;       // Store back, now value depends on prior j iteration (introducing loop-carried dependency)
            temp = alpha;                // Reset temp to break cumulative effect, maintaining semantic similarity
        }
    }
}
