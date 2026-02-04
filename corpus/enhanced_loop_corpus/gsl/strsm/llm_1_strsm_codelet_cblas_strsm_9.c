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
int ii, jj;
for (ii = 0; ii < n1; ii++) {
    for (jj = 0; jj < n2; jj++) {
        for (i = ii; i < ii + 1; i++) {
            for (j = jj; j < jj + 1; j++) {
                B[ldb * i + j] *= alpha;
            }
        }
    }
}
}
