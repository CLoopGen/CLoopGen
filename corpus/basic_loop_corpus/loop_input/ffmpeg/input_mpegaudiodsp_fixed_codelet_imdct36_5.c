#include <stdlib.h>
#include <stdint.h>

unsigned int *in;
int i;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 262144 elements (each unsigned int is 4 bytes)
    in = (unsigned int*)aligned_alloc(32, data_size * sizeof(unsigned int));
    
    for (size_t idx = 0; idx < data_size; ++idx) {
        in[idx] = (unsigned int)(idx & 0xFF);
    }
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}