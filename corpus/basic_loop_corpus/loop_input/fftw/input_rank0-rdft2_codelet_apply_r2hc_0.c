#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *r0;
R *cr;
R *ci;
INT i;
INT vl;
INT ivs;
INT ovs;

static R *r0_data;
static R *cr_data;
static R *ci_data;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec on modern CPU)
    const size_t num_elements = total_data_size / sizeof(R);
    
    // Ensure the loop runs with step 4 and starts at i=4, so we need at least 8 elements (i <= vl)
    vl = (num_elements > 8) ? num_elements - (num_elements % 4) : 8;
    
    ivs = 1;
    ovs = 1;
    
    // Allocate aligned memory to avoid alignment issues
    r0_data = aligned_alloc(32, (vl + 4) * sizeof(R));
    cr_data = aligned_alloc(32, (vl + 4) * 2 * sizeof(R)); // Larger output buffer
    ci_data = aligned_alloc(32, (vl + 4) * 2 * sizeof(R));

    if (!r0_data || !cr_data || !ci_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize input data
    for (INT k = 0; k < vl + 4; ++k) {
        r0_data[k] = (R)(k * 1.5);
    }
    
    // Zero-initialize output buffers
    memset(cr_data, 0, (vl + 4) * 2 * sizeof(R));
    memset(ci_data, 0, (vl + 4) * 2 * sizeof(R));

    // Set pointers to start of data
    r0 = r0_data;
    cr = cr_data;
    ci = ci_data;
}

// Cleanup function to free allocated memory (not required by spec but good practice)
void cleanup_vars() {
    free(r0_data);
    free(cr_data);
    free(ci_data);
}