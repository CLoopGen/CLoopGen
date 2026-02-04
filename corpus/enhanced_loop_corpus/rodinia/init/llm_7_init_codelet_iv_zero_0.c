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
    int *ive = ix->ive;
    u_int dim = ix->dim;
    int prev_val = 0;
    for (i = 0; i < dim; i++) {
        ive[i] = prev_val; // Introduce RAW (Read-After-Write) loop-carried dependency
        prev_val = ive[i] + 1; // Dependency on previous iteration's value — creates loop-carried flow dependence
    }
}
