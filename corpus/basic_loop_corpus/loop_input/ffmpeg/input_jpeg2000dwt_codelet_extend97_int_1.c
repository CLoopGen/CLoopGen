#include <stdlib.h>
#include <stdint.h>

int32_t *p;
int i0;
int i1;
int i;

static int32_t *internal_p;
static size_t data_size = 1 << 20; // 4MB of data (1M int32_t elements)

void init_vars() {
    internal_p = (int32_t*)aligned_alloc(32, data_size * sizeof(int32_t));
    if (!internal_p) exit(1);
    
    p = internal_p;
    
    for (size_t idx = 0; idx < data_size; idx++) {
        p[idx] = (int32_t)(idx * 789);
    }
    
    i0 = 10000;
    i1 = 20000;
    
    i = 0;
}

__attribute__((destructor))
static void cleanup() {
    if (internal_p) {
        free(internal_p);
    }
}