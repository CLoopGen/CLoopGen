#include <inttypes.h>

unsigned int i;
unsigned char hmac_key[64];

void init_vars() {
    for (unsigned int j = 0; j < sizeof(hmac_key); j++) {
        hmac_key[j] = j & 0xFF;
    }
}