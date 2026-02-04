#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t keybuf[48] = {0};
uint32_t keys[12] = {0};
int i = 0;

void init_vars() {
    for (int j = 0; j < 48; j++) {
        keybuf[j] = (uint8_t)(j * j + 3 * j + 17);
    }
    for (int j = 0; j < 12; j++) {
        keys[j] = 0;
    }
    i = 0;
}