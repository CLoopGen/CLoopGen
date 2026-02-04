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



void loop() {
    int start = iv->dim;
    int end = (new_dim > iv->max_dim) ? iv->max_dim : new_dim;
    for (i = start; i < end; i += 2) {
        iv->ive[i] = 0;
        if (i + 1 < end)
            iv->ive[i + 1] = 0;
    }
}
