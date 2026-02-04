#include <inttypes.h>

unsigned short data[131072]; // 256KB of data (131072 elements * 2 bytes)
unsigned short *x = data;
int i;

void init_vars() {
    // No additional initialization needed beyond static definitions
}