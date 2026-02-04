#include <inttypes.h>

uint64_t *a;
uint64_t aa[4];
unsigned int i;

static uint64_t buffer[1024]; // 8KB = 1024 * 8 bytes

void init_vars() {
    a = buffer;
    for (int j = 0; j < 1024; j++) {
        buffer[j] = j;
    }
}