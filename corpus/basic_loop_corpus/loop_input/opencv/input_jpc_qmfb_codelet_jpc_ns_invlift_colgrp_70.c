#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_storage;
static jpc_fix_t *hptr2_storage;
static size_t total_elements = 16777216; // ~16M elements, adjust for ~0.01s runtime

void init_vars() {
    lptr2_storage = calloc(total_elements, sizeof(jpc_fix_t));
    hptr2_storage = calloc(total_elements, sizeof(jpc_fix_t));

    if (!lptr2_storage || !hptr2_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx & 0xFFFFF);
        hptr2_storage[idx] = (jpc_fix_t)((idx << 5) & 0xFFFFF);
    }

    lptr2 = lptr2_storage;
    hptr2 = hptr2_storage;
}