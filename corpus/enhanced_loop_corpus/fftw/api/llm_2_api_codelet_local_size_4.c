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

extern  dtensor *sz;
extern ptrdiff_t *local_n;
extern ptrdiff_t *local_start;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order
    for (i = sz->rnk - 1; i >= 0; --i) {
        local_n[i] = 0;
        local_start[i] = 0;
    }
}
