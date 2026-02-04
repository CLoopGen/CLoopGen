#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct HuffTable {
    int code;
    int length;
} HuffTable;

uint8_t bits[17];
uint8_t val[256 * 1024]; // 256KB to fit within target runtime
HuffTable distincts[256];
int i;
int nval = 256;

void init_vars() {
    for (int j = 0; j < 17; j++) {
        bits[j] = 0;
    }
    for (int j = 0; j < 256; j++) {
        distincts[j].code = rand() & 0xFF;
        distincts[j].length = rand() % 16 + 1;
    }
    nval = 256;
}