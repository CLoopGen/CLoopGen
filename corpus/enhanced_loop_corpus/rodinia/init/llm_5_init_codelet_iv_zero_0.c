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
    for (i = 0; i < ix->dim; i++) {
        if ((i & 1) == 0) {
            ix->ive[i] = 0;
        } else {
            continue;
        }
    }
}
