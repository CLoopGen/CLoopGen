#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc;
uint8_t *src;

static uint8_t data[1 << 24]; // ~16.7 MB to target ~0.01 sec runtime

void init_vars() {
    stride = 1;
    i = 0;
    dc = 0;
    for (int j = 0; j < (int)(sizeof(data)); j++) {
        data[j] = j & 0xFF;
    }
    src = data + 16; // ensure i - stride >= 0 when i=0 and stride=1
}