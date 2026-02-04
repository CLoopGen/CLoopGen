#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

extern IVEC *iv1;
extern u_int i;
extern int *out_ive;
extern int *iv1_ive;
extern int *iv2_ive;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int *indices = (u_int*)malloc(iv1->dim * sizeof(u_int));
    for (i = 0; i < iv1->dim; i++) {
        indices[i] = iv1->dim - 1 - i; // Reverse access pattern
    }
    for (i = 0; i < iv1->dim; i++) {
        u_int idx = indices[i];
        out_ive[idx] = iv1_ive[idx] + iv2_ive[idx];
    }
    free(indices);
}
