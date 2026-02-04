#include <stdint.h>
#include <stdlib.h>

uint64_t table[8][256];
uint64_t crc;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 256; j++) {
            table[i][j] = ((uint64_t)rand() << 32) | rand();
        }
    }
    crc = ((uint64_t)rand() << 32) | rand();
}