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
    float local_alpha = alpha;
    for (i = 0; i < n1; i++) {
        float *row_start = &B[ldb * i];
        for (j = 0; j < n2; j++) {
            row_start[j] *= local_alpha;
        }
        local_alpha = alpha; // Re-establish value (neutral operation, creates WAW-like pattern without effect)
    }
}
