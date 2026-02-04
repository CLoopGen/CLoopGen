#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

extern IVEC *ix;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int double_dim = 2 * ix->dim;
    for (i = 0; i < double_dim; i++) {
        int index = i % ix->max_dim;
        if (index < ix->dim) {
            ix->ive[index] = (ix->ive[index] * 3 + 1) ^ 0x55;
        }
    }
}
