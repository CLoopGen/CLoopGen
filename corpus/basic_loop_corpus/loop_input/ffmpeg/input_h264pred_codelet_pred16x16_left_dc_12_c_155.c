#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc;
uint16_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 524,288 uint16_t elements
    src = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * (data_size / sizeof(uint16_t)));
    
    if (!src) exit(1);

    for (size_t idx = 0; idx < (data_size / sizeof(uint16_t)); ++idx) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }

    stride = (ptrdiff_t)(data_size / sizeof(uint16_t)) / 17; 
    if (stride < 1) stride = 1;

    i = 0;
    dc = 0;
}