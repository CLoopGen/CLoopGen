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
    for (i = 0; i < iv1->dim; i++) {
        if (iv1_ive[i] != 0 || iv2_ive[i] != 0) {
            out_ive[i] = iv1_ive[i] - iv2_ive[i];
        } else {
            out_ive[i] = 0;
        }
    }
}
