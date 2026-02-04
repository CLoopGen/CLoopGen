#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
jpc_fix_t *lptr2;
int i;

static jpc_fix_t *lptr2_storage;

void init_vars() {
    size_t data_size = 1 << 20; // ~4MB of data (1M elements * 4 bytes)
    numcols = data_size;
    lptr2_storage = (jpc_fix_t *)calloc(data_size, sizeof(jpc_fix_t));
    if (!lptr2_storage) {
        exit(1);
    }
    lptr2 = lptr2_storage;
}