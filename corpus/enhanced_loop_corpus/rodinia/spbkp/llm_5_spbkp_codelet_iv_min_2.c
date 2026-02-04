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
extern int i;
extern int i_min;
extern int min_val;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < iv->dim; i++) {
        tmp = iv->ive[i];
        if (tmp >= min_val) continue;
        min_val = tmp;
        i_min = i;
    }
}
