#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t count[16];
unsigned int len;

void init_vars() {
    for (int i = 0; i < 16; i++) {
        count[i] = 0;
    }
    len = 0;
}