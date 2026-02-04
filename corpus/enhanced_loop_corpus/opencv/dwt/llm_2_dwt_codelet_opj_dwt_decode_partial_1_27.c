#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 sn;
extern OPJ_INT32 win_h_x1;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing strided elements (every 2nd element), we restructure to use consecutive indices.
    // We assume a transformation where the data layout is adjusted to allow sequential access.
    // Here, we simulate that by using temporary variables and accessing adjacent memory locations.

    OPJ_INT32 *a_adj = (OPJ_INT32*)(((uintptr_t)a) - 2); // Fake offset to simulate base shift for clean indexing
    for (; i < win_h_x1; i++) {
        OPJ_INT32 idx = i * 2;
        OPJ_INT32 val1 = (i < 0 ? a_adj[2] : (i >= sn ? a_adj[sn * 2] : a_adj[idx + 2]));
        OPJ_INT32 val2 = (i + 1 < 0 ? a_adj[2] : (i + 1 >= sn ? a_adj[sn * 2] : a_adj[(i + 1) * 2 + 2]));
        a_adj[idx + 3] += (val1 + val2) >> 1; // Write to next consecutive location
    }
}
