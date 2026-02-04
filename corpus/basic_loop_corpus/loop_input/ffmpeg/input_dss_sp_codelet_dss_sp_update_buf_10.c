#include <stdlib.h>
#include <stdint.h>

int32_t *vector;
int i;

void init_vars() {
    const size_t data_size = 16777216; // 16 MB of data (adjustable for ~0.01 sec runtime)
    vector = aligned_alloc(32, data_size * sizeof(int32_t));
    
    for (size_t idx = 0; idx < data_size; ++idx) {
        vector[idx] = rand();
    }
}

__attribute__((constructor))
static void constructor_call() {
    init_vars();
}