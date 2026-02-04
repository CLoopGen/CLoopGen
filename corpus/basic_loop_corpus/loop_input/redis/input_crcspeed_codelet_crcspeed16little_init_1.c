#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t table[8][256];
uint16_t crc;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 256; j++) {
            table[i][j] = (uint16_t)(i * 256 + j);
        }
    }
    crc = 0x1234;
}