#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

uint8_t buf[1000];
size_t i;

void init_vars() {
    // No additional initialization needed beyond zero-initialization
    // buf is large enough (1000 bytes) to accommodate writes up to index 19
    // i will be initialized in the loop itself
}