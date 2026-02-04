#include <inttypes.h>
#include <string.h>

unsigned char tick_nonce[8];
size_t i;
uint64_t nonce;

void init_vars() {
    nonce = 0xABCDEF1234567890ULL;
    memset(tick_nonce, 0, 8);
    i = 8;
}