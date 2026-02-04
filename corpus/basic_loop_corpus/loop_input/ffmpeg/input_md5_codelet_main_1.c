#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

volatile uint8_t in[1000];
int i;

void init_vars() {
    // No additional initialization required beyond zero-initialization
    // Globals are already zero-initialized by default
}