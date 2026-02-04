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
    for (i = iv->dim; i < new_dim; i += 2) {
        iv->ive[i] = 0;
        if (i + 1 < new_dim) {
            iv->ive[i + 1] = 0;
        }
    }
}
