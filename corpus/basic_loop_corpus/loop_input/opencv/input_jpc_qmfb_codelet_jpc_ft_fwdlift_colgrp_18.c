#include <stdlib.h>
#include <stdint.h>

typedef int_fast32_t jpc_fix_t;

jpc_fix_t *lptr2;
int i;

static jpc_fix_t *buffer;

void init_vars() {
    size_t data_size = 1 << 20;
    buffer = (jpc_fix_t *)calloc(data_size, sizeof(jpc_fix_t));
    if (!buffer) exit(1);
    lptr2 = buffer;
}

void cleanup_vars() {
    free(buffer);
}