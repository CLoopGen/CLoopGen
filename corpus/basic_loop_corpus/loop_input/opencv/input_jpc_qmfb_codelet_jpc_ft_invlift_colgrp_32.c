#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

jpc_fix_t *lptr2;
int i;

static jpc_fix_t *array_storage;
static size_t total_elements = (1 << 24) / sizeof(jpc_fix_t); // ~16M elements, ~64MB for int_fast32_t

void init_vars() {
    array_storage = calloc(total_elements, sizeof(jpc_fix_t));
    if (!array_storage) exit(1);
    for (size_t idx = 0; idx < total_elements; ++idx) {
        array_storage[idx] = (jpc_fix_t)(0x80000000U); 
    }
    lptr2 = array_storage;
}

__attribute__((destructor))
static void cleanup() {
    free(array_storage);
}