#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT b[2];
} ddim;

typedef struct {
    int rnk;
    ddim dims[1];
} dtensor;

extern int i;
extern dtensor *sz;
extern INT Nafter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic for better spatial locality
    INT *n_ptr = &sz->dims[2].n;
    for (i = 2; i < sz->rnk; ++i)
        Nafter *= n_ptr[i - 2];
}
