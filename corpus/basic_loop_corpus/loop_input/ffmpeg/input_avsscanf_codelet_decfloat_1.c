#include <stdint.h>
#include <string.h>

uint32_t x[128];
int z;

void init_vars() {
    memset(x, 0, sizeof(x));
    z = 127;
    x[0] = 1;
}