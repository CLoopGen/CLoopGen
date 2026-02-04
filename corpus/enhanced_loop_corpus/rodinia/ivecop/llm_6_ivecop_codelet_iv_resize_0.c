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
    int *ive_ptr = iv->ive + iv->dim;
    for (i = iv->dim; i < new_dim; i++) {
        *ive_ptr = 0;
        ive_ptr++;
    }
}
