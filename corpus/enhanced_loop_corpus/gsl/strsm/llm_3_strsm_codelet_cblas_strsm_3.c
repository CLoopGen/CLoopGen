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
    // Variant 2: Consecutive memory access - flatten the loop and access B sequentially
    int idx;
    for (idx = 0; idx < n1 * n2; idx++) {
        B[idx] *= alpha;
    }
}
