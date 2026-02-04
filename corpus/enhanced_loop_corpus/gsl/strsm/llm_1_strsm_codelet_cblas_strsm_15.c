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
    int i;
    for (i = 0; i < n1; i++) {
        int j1;
        for (j1 = 0; j1 < n2; j1 += 2) {
            if (j1 < n2) {
                B[ldb * i + j1] *= alpha;
            }
            if (j1 + 1 < n2) {
                B[ldb * i + j1 + 1] *= alpha;
            }
        }
    }
}
