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
    // Variant 2: Indirect memory access using an index map (reverse order access pattern)
    u_int *index_map = (u_int*)malloc(n * sizeof(u_int));
    for (i = 0; i < n; i++) {
        index_map[i] = n - 1 - i;  // reverse indexing
    }
    for (i = 0; i < n; i++) {
        pivot->pe[index_map[i]] = index_map[i];
    }
    free(index_map);
}
