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
    if (in->dim > 0) {
        i = 0;
        for (; i < in->dim; ) {
            out->ive[i] = in->ive[i];
            i++;
        }
    }
}
