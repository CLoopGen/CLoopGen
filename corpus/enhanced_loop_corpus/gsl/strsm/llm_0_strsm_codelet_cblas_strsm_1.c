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
    int k;
    for (k = 0; k < n1 * n2; k++) {
        int i = k / n2;
        int j = k % n2;
        B[ldb * i + j] *= alpha;
    }
}
