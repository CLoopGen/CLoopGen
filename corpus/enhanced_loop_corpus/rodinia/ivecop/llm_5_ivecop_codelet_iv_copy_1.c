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
    for (i = 0; i < in->dim; i++) {
        if (in->ive[i] >= 0) {
            out->ive[i] = in->ive[i];
        } else {
            out->ive[i] = 0;
        }
    }
}
