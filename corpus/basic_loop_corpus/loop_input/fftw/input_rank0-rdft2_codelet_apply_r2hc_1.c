#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

static R *r0_buf;
static R *cr_buf;
static R *ci_buf;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB of input data for sufficient runtime
    const size_t num_elements = data_size / sizeof(R);

    r0_buf = aligned_alloc(32, data_size);
    cr_buf = aligned_alloc(32, data_size);
    ci_buf = aligned_alloc(32, data_size);

    if (!r0_buf || !cr_buf || !ci_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        r0_buf[idx] = (R)(idx + 1) * 0.5;
        cr_buf[idx] = (R)0.0;
        ci_buf[idx] = (R)0.0;
    }

    r0 = r0_buf;
    cr = cr_buf;
    ci = ci_buf;
    i = 0;
    vl = (INT)(num_elements) - 4; // ensures i < vl + 4 does not exceed allocated bounds
    ivs = 1;
    ovs = 1;
}