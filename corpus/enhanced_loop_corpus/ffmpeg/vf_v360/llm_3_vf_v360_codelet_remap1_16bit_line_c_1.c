#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern ptrdiff_t in_linesize;
extern  int16_t * u;
extern  int16_t * v;
extern  uint16_t * s;
extern uint16_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (linearized) indirect access via temporary index array
    // Precompute the indirect indices into a local array to separate address calculation
    // from data fetching, enabling better optimization and clearer memory access pattern.
    int16_t* u_local = u;
    int16_t* v_local = v;
    uint16_t* s_base = s;
    uint16_t* d_local = d;
    ptrdiff_t linesize = in_linesize;

    // Allocate stack storage for computed indices (if width is reasonably small)
    // Using a VLA for automatic allocation; ensures consecutive access later
    ptrdiff_t *indices = (ptrdiff_t*)alloca(width * sizeof(ptrdiff_t));
    
    for (int x = 0; x < width; x++) {
        indices[x] = v_local[x] * linesize + u_local[x];
    }

    // Now perform consecutive store and fetch using precomputed indices
    for (int x = 0; x < width; x++) {
        d_local[x] = s_base[indices[x]];
    }
}
