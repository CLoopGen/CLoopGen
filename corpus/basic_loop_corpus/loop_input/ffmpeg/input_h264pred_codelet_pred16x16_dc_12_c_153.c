#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc;
uint16_t *src;

void init_vars() {
    stride = 1;
    dc = 0;
    src = (uint16_t*)calloc(32, sizeof(uint16_t));
}

__attribute__((destructor))
static void cleanup() {
    free(src);
}