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
    float alpha_sqr = alpha * alpha;
    int idx;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2 - 1; j += 2) {
            idx = ldb * i + j;
            B[idx] *= alpha;
            B[idx + 1] *= alpha;
        }
        if (j == n2 - 1) {
            B[ldb * i + j] *= alpha;
        }
    }
}
