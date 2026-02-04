#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    int *ive;
} IVEC;

extern IVEC *iv;
extern int new_dim;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = iv->dim; i < new_dim; i++) {
        if (i >= 0)
            iv->ive[i] = 0;
        else
            continue;
    }
}
