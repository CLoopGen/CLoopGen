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
    for (i = 0; i < ix->dim; i += 2) {
        if (i < ix->dim) ix->ive[i] = 0;
        if (i + 1 < ix->dim) ix->ive[i + 1] = 0;
    }
}
