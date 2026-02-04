#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int max;
uint16_t count[16];

void init_vars() {
    for (int i = 0; i < 16; i++) {
        count[i] = 0;
    }
    // Set one element to non-zero to ensure loop breaks predictably
    count[7] = 1;
}