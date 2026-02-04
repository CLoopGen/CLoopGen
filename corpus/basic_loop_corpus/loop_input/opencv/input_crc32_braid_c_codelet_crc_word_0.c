#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint64_t z_word_t;

uint32_t crc_table[256];
z_word_t data;
int k;

void init_vars() {
    for (int i = 0; i < 256; i++) {
        uint32_t c = i;
        for (int j = 0; j < 8; j++) {
            if (c & 1) {
                c = 0xEDB88320U ^ (c >> 1);
            } else {
                c = c >> 1;
            }
        }
        crc_table[i] = c;
    }

    data = 0x1234567812345678ULL;
    k = 0;
}