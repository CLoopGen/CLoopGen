#include <inttypes.h>

int tag;
int i;
int ttag;

void init_vars() {
    tag = 0x10000000; // Large enough to make the loop run ~0.01 seconds
}