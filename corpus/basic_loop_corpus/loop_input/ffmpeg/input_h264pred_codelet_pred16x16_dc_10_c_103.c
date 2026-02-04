#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

ptrdiff_t stride;
int i;
int dc;
uint16_t *src;

void init_vars() {
    stride = 1;
    dc = 0;
    i = 0;

    size_t num_elements = 16 + stride;
    src = (uint16_t*)calloc(num_elements, sizeof(uint16_t));
    if (!src) exit(1);
}