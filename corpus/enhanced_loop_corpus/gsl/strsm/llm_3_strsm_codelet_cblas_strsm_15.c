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
    // Variant 2: Column-Major Consecutive Access Pattern
    // Transpose the loop order to iterate over columns first, then rows
    // This results in consecutive memory accesses when ldb == n1 (or small), improving cache performance
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            B[ldb * i + j] *= alpha;
        }
    }
}
