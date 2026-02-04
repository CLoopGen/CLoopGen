#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

extern PERM *px;
extern u_int i;
extern u_int j;
extern u_int entry;
extern u_int ok;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via reversed access pattern)
    u_int *indices = alloca(i * sizeof(u_int));
    for (j = 0; j < i; j++)
        indices[j] = i - 1 - j;  // Reverse mapping
    for (j = 0; j < i; j++)
        ok &= (entry != px->pe[indices[j]]);
}
