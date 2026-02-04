#include <inttypes.h>

uint8_t *out;
int out_len;
uint64_t digit;

static uint8_t out_buffer[131072]; // 128 KB

void init_vars() {
    out = out_buffer;
    out_len = sizeof(out_buffer);
    digit = 0xABCDEF1234567890ULL;
}