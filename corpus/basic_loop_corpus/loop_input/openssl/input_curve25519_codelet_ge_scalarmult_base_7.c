#include <inttypes.h>

signed char e[64];
signed char carry;
int i;

void init_vars() {
    for (int j = 0; j < 64; ++j) {
        e[j] = (signed char)(j * 37 % 128 - 64);
    }
    carry = 5;
    i = 0;
}