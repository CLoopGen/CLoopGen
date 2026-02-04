#include <stdint.h>
#include <string.h>

unsigned char *agenkey;
size_t agenkeylen;
size_t i;

static unsigned char agenkey_storage[512 * 1024]; // 512 KB data

void init_vars() {
    agenkeylen = sizeof(agenkey_storage);
    agenkey = agenkey_storage;
    memset(agenkey, 0, agenkeylen);
    if (agenkeylen > 0) {
        agenkey[agenkeylen - 1] = 1;
    }
    i = 0;
}