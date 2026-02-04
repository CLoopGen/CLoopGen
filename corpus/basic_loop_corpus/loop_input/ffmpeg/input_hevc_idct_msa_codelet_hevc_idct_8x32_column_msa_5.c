#include <stdint.h>
#include <stdlib.h>

uint8_t i;
int16_t *filter_ptr0;

static int16_t *filter_data;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    filter_data = (int16_t*)aligned_alloc(32, total_size);
    
    if (!filter_data) exit(1);
    
    for (size_t idx = 0; idx < total_size / sizeof(int16_t); idx++) {
        filter_data[idx] = (int16_t)(idx & 0xFFFF);
    }
    
    filter_ptr0 = filter_data;
}

// Ensure variables are defined at file scope
__attribute__((destructor))
static void cleanup() {
    free(filter_data);
}