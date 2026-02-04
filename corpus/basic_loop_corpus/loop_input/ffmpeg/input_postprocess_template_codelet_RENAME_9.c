#include <inttypes.h>
#include <stdlib.h>

int x;
int y;

static uint8_t *colsrc_ptr;
static uint8_t *data_buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    data_buffer = (uint8_t *)aligned_alloc(32, data_size);
    
    if (!data_buffer) exit(1);
    
    for (size_t i = 0; i < data_size; i++) {
        data_buffer[i] = rand() & 0xFF;
    }
    
    colsrc_ptr = data_buffer;
}

// Assign colsrc to point to allocated buffer
uint8_t *colsrc = NULL;

__attribute__((constructor))
static void constructor() {
    init_vars();
    colsrc = colsrc_ptr;
}