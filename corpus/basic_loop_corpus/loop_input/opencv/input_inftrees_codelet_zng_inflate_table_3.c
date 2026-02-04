#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int min;
unsigned int max = 131072;
uint16_t count[16];

void init_vars() {
    for (int i = 0; i < 16; i++) {
        count[i] = 0;
    }
    count[8] = 1;
    min = 0;
}