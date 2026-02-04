#include <stddef.h>
#include <stdint.h>

int rnk = 4;
ptrdiff_t local_n_storage[] = {256, 256, 256, 256};
ptrdiff_t *local_n = local_n_storage;
int i;
ptrdiff_t N = 1;

void init_vars() {
    rnk = 4;
    local_n_storage[0] = 256;
    local_n_storage[1] = 256;
    local_n_storage[2] = 256;
    local_n_storage[3] = 256;
    N = 1;
}