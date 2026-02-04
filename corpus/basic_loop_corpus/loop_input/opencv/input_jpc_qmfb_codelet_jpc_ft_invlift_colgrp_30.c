#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr_base;
static jpc_fix_t *hptr_base;
static size_t data_size;
static size_t alignment = 64;

void init_vars() {
    data_size = 1 << 20; // 1MB of data

    // Allocate aligned memory to avoid cache effects and ensure safety
    if (posix_memalign((void**)&lptr_base, alignment, data_size * sizeof(jpc_fix_t)) != 0) {
        exit(1);
    }
    if (posix_memalign((void**)&hptr_base, alignment, data_size * sizeof(jpc_fix_t)) != 0) {
        exit(1);
    }

    // Initialize arrays with non-zero values to allow observable behavior
    for (size_t idx = 0; idx < data_size; ++idx) {
        lptr_base[idx] = (jpc_fix_t)(idx & 0xFF);
        hptr_base[idx] = (jpc_fix_t)((idx + 1) & 0xFF);
    }

    // Set initial pointers
    lptr2 = lptr_base;
    hptr2 = hptr_base;

    // Set stride to a reasonable value within bounds (e.g., ~sqrt(size))
    stride = (int)(data_size >> 5); // ensures lptr2[stride] is valid at beginning
}