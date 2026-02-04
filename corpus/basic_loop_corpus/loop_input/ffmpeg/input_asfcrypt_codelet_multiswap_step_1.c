#include <stdint.h>
#include <stdlib.h>

uint32_t keys[12];
uint32_t v;
int i;

void init_vars() {
    for (int j = 0; j < 12; j++) {
        keys[j] = (uint32_t)(j + 1) * 314159;
    }
    v = 0x12345678;
    i = 0;
}