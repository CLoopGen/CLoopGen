#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

extern IVEC *in;
extern IVEC *out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < in->dim; i++)
        out->ive[i] = in->ive[i-1];
    if (in->dim > 0)
        out->ive[0] = in->ive[0];
}
