#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

extern PERM *pivot;
extern u_int i;
extern u_int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int *indices = (u_int*)malloc(m * sizeof(u_int));
    for (u_int j = 0; j < m; j++) {
        indices[j] = m - 1 - j;
    }
    for (u_int j = 0; j < m; j++) {
        pivot->pe[indices[j]] = indices[j];
    }
    free(indices);
}
