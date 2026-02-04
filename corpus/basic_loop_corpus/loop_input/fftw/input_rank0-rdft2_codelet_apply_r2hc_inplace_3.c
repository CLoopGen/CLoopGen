#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *ci;
INT i;
INT vl;
INT ovs;

static R *internal_ci_data;
static INT internal_vl_val;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; 
    const size_t element_size = sizeof(R);
    const INT num_elements = data_size / element_size;

    internal_ci_data = aligned_alloc(32, data_size);
    if (!internal_ci_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(internal_ci_data, 0, data_size);

    ci = internal_ci_data;
    i = 0;
    internal_vl_val = num_elements - 4;
    vl = internal_vl_val;
    ovs = 1;
}