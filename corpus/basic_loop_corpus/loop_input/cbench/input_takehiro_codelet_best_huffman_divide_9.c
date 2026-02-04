#include <stdint.h>

int r0;
int r3_bits[25];

void init_vars() {
    r0 = 0;
    for (int i = 0; i < 25; i++) {
        r3_bits[i] = 0;
    }
}