#include <inttypes.h>
#include <string.h>

size_t md_block_size;
unsigned char hmac_pad[128];
size_t i;

void init_vars() {
    md_block_size = 128;
    memset(hmac_pad, 0, 128);
}