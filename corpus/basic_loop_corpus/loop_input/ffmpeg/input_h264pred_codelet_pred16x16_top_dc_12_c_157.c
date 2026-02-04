#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride = 1;
int i;
int dc = 0;
uint16_t *src;

void init_vars() {
    const size_t data_size = 256 * 1024 * sizeof(uint16_t);
    src = aligned_alloc(32, data_size);
    stride = 16;
    for (i = 0; i < 16 + stride; i++) {
        src[i] = i & 0xFFFF;
    }
    dc = 0;
}