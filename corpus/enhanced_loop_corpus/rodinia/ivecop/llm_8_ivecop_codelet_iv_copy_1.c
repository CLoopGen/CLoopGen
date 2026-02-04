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
    int stride = 2;
    for (i = 0; i < in->dim; i += stride) {
        if (i + 1 < in->dim) {
            out->ive[i] = in->ive[i];
            out->ive[i + 1] = in->ive[i + 1];
        } else {
            out->ive[i] = in->ive[i];
        }
    }
}
