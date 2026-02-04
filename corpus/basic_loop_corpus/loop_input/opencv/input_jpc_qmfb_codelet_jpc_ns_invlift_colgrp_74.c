#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int stride = 16;

static jpc_fix_t *lptr2_base;
static jpc_fix_t *hptr2_base;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

void init_vars() {
    const size_t total_size = 1 << 20; // ~1MB of data per array
    lptr2_base = aligned_alloc(32, total_size * sizeof(jpc_fix_t));
    hptr2_base = aligned_alloc(32, total_size * sizeof(jpc_fix_t));

    if (!lptr2_base || !hptr2_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        lptr2_base[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_base[idx] = (jpc_fix_t)(idx % 500);
    }

    lptr2 = lptr2_base;
    hptr2 = hptr2_base;
}

__attribute__((destructor))
void cleanup() {
    free(lptr2_base);
    free(hptr2_base);
}