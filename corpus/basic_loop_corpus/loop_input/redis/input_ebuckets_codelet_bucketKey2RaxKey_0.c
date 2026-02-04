#include <stdint.h>
#include <stdlib.h>

uint64_t bucketKey;
unsigned char *raxKey;

void init_vars() {
    raxKey = aligned_alloc(64, 1 << 20);
}

void loop();