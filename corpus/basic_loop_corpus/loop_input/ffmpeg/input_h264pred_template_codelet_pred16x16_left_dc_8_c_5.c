#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

ptrdiff_t stride;
int i;
int dc;
uint8_t *src;

uint8_t *src_buffer;

void init_vars() {
    stride = 65536;
    dc = 0;
    
    size_t buffer_size = 16 * stride;
    src_buffer = (uint8_t*)calloc(buffer_size, sizeof(uint8_t));
    if (!src_buffer) exit(1);
    
    for (size_t idx = 0; idx < buffer_size; idx++) {
        src_buffer[idx] = rand() % 256;
    }
    
    src = src_buffer + 1;
}
// Note: The actual loop function is defined externally and not included here.