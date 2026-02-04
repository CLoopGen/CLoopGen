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
    u_int step = 2;
    for (i = 0; i < iv1->dim; i += step) {
        if (i + 1 < iv1->dim) {
            out_ive[i]     = iv1_ive[i] + iv2_ive[i];
            out_ive[i + 1] = iv1_ive[i + 1] + iv2_ive[i + 1];
        } else {
            out_ive[i] = iv1_ive[i] + iv2_ive[i];
        }
    }
}
