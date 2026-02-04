#include <inttypes.h>

uint32_t w = 0x12345678;

static uint8_t p_data[1024 * 1024] __attribute__((aligned(32)));
uint8_t *p = p_data;

int i;

void init_vars() {
    w = 0x87654321;
    for (int j = 0; j < 1024 * 1024; j++) {
        p[j] = 0;
    }
    i = 0;
}