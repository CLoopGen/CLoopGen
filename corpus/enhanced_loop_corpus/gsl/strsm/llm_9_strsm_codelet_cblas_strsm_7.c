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
int stride = (alpha > 1.0f) ? 1 : 2;
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        B[ldb * i + j] *= alpha;
        B[ldb * i + j] += (B[ldb * i + j] < 0.0f) ? -0.01f : 0.01f;
    }
}
}
