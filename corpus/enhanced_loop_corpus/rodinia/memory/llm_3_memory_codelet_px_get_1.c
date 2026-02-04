#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

extern int size;
extern PERM *permute;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    u_int *indices = (u_int*)malloc(size * sizeof(u_int));
    for (i = 0; i < size; i++)
        indices[i] = size - 1 - i;  // reverse order access
    for (i = 0; i < size; i++)
        permute->pe[indices[i]] = indices[i];
    free(indices);
}
