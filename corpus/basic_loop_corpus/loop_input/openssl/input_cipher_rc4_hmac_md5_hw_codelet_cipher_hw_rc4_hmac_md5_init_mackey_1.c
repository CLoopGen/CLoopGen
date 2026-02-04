#include <inttypes.h>

unsigned int i;
unsigned char hmac_key[64];

void init_vars() {
    for (i = 0; i < sizeof(hmac_key); i++) {
        hmac_key[i] = (unsigned char)(i & 0xFF);
    }
    i = 0;
}