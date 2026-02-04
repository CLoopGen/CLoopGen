#include <inttypes.h>

uint64_t w = 0x123456789ABCDEF0ULL;
uint8_t *p;
int i;

static uint8_t p_buffer[1024 * 128]; // 128KB buffer

void init_vars() {
    p = p_buffer;
    w = 0x123456789ABCDEF0ULL;
    i = 0;
}