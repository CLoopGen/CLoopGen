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
    for (i = sz->rnk - 1; i >= 0; --i) {
        local_start[i] = 0;
        local_n[i] = 0; // WAW dependency removed by reversing order; no loop-carried deps
    }
    // Introduce artificial dependency: ensure finalization in reverse order
    if (sz->rnk > 0)
        local_n[0] = local_start[sz->rnk - 1]; // Artificial RAW to bind loop results
}
