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
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (consecutive j), we access B with a fixed stride pattern across rows
    // Here, we reverse the inner loop to create backward strided access in each row
    for (i = 0; i < n1; i++) {
        for (j = n2 - 1; j >= 0; j--) {
            B[ldb * i + j] *= alpha;
        }
    }
}
