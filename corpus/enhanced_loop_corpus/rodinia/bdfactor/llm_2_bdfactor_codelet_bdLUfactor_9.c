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
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    int stride = 2;
    for (i = 0; i < n; i += stride)
        pivot->pe[i] = i;
    for (i = 1; i < n; i += stride)
        pivot->pe[i] = i;
}
