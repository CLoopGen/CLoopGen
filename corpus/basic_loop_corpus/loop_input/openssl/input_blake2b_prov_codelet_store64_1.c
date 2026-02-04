#include <inttypes.h>
#include <stdlib.h>

uint64_t w = 0x0706050403020100ULL;

static uint8_t p_data[1024 * 1024]; // 1MB buffer
uint8_t *p = p_data;

int i;

void init_vars() {
    w = 0x0706050403020100ULL;
    for (int j = 0; j < 1024 * 1024; j++) {
        p[j] = 0;
    }
}