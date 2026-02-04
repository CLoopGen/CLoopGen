#include <stdint.h>
#include <string.h>

typedef uint64_t QUIC_PN;

QUIC_PN pn = 0x123456789ABCDEF0ULL;
int nonce_len = 16;
unsigned char nonce[16];
size_t i;

void init_vars() {
    pn = 0x123456789ABCDEF0ULL;
    nonce_len = 16;
    memset(nonce, 0, sizeof(nonce));
    i = 0;
}