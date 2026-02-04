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
    int idx;
    float alpha_val = alpha;
    for (i = 0; i < n1; i++) {
        idx = ldb * i;
        for (j = 0; j < n2; j++) {
            B[idx + j] *= alpha_val;
        }
    }
}
