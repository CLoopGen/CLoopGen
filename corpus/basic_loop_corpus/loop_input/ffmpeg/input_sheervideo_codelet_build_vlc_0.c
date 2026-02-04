#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *len;
int count;
uint32_t codes[1024];
uint8_t bits[1024];
uint16_t syms[1024];
uint64_t _usr_index;
int i;

#define index _usr_index

void init_vars() {
    count = 1024;
    len = (uint8_t*)malloc(count * sizeof(uint8_t));
    if (!len) {
        exit(1);
    }
    for (int j = 0; j < count; j++) {
        len[j] = (j % 32) + 1;
    }
    index = 0x12345678ULL;
}