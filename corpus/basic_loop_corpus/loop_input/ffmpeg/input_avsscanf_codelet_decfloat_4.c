#include <stdint.h>

uint32_t x[128];
int j;
int k;

void init_vars() {
    j = 0;
    k = 0;
    for (int i = 0; i < 128; i++) {
        x[i] = 1;
    }
}