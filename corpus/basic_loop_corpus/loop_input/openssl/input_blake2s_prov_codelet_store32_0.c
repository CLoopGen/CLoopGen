#include <stdint.h>
#include <string.h>

uint32_t w = 0x1A2B3C4D;

static uint8_t p_data[1024 * 128]; // 128KB of data
uint8_t *p = p_data;
int i;

void init_vars() {
    w = 0x1A2B3C4D;
    memset(p, 0, 1024 * 128);
    i = 0;
}