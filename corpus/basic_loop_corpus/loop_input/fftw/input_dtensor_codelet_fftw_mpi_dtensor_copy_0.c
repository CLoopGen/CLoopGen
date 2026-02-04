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

// Define external variables
dtensor *sz;
dtensor *x;
int i;

// Helper function to initialize variables
void init_vars() {
    // Set rank to a reasonable size for timing ~0.01s
    // The operation is very lightweight (copying ddim structs), so we need enough iterations
    // Each iteration copies one ddim (size of 3*sizeof(INT) effectively)
    // To ensure ~0.01s runtime, aim for several million iterations
    
    const int effective_rank = 5000000; // Empirically chosen for ~0.01s on modern CPU
    
    // Allocate sz with sufficient rank
    size_t sz_size = sizeof(dtensor) + (effective_rank - 1) * sizeof(ddim);
    sz = (dtensor*)calloc(1, sz_size);
    if (!sz) exit(1);
    
    sz->rnk = effective_rank;
    
    // Initialize sz->dims content
    for (int j = 0; j < sz->rnk; ++j) {
        sz->dims[j].n = j;
        sz->dims[j].b[0] = j * 2;
        sz->dims[j].b[1] = j * 2 + 1;
    }
    
    // Allocate x with same capacity
    size_t x_size = sizeof(dtensor) + (effective_rank - 1) * sizeof(ddim);
    x = (dtensor*)calloc(1, x_size);
    if (!x) exit(1);
    
    x->rnk = effective_rank; // Ensure x can hold all elements
    
    // Initialize i to 0 (loop counter)
    i = 0;
}