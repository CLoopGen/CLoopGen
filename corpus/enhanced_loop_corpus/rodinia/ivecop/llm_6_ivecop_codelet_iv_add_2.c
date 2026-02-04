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
    u_int dim = iv1->dim;
    int *out = out_ive;
    int *iv1_data = iv1_ive;
    int *iv2_data = iv2_ive;
    for (i = 0; i < dim; i++) {
        out[i] = iv1_data[i] + iv2_data[i];
        out[i+1] = iv1_data[i] - iv2_data[i]; // Introduces WAW and WAR dependency on 'out'; creates loop-carried dependence via memory location out[i+1]
    }
}
