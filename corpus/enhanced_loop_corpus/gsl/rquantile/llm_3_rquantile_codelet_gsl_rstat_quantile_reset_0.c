#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double p;
    double q[5];
    int npos[5];
    double np[5];
    double dnp[5];
    size_t n;
} gsl_rstat_quantile_workspace;

extern gsl_rstat_quantile_workspace *w;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    // Simulates non-sequential access via a lookup table
    const size_t index_map[5] = {2, 0, 4, 1, 3}; // Arbitrary permutation
    for (i = 0; i < 5; ++i)
        w->npos[index_map[i]] = index_map[i] + 1;
}
