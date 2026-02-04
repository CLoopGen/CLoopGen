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
    float *restrict local_B = B;
    int local_ldb = ldb;
    float local_alpha = alpha;
    for (i = 0; i < n1; i++) {
        int base_index = local_ldb * i;
        for (j = 0; j < n2; j++) {
            local_B[base_index + j] *= local_alpha;
        }
    }
}
