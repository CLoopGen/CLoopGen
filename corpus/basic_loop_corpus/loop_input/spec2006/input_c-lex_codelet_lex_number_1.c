#include <inttypes.h>

int base;
int count;
unsigned int parts[16];
int n;

void init_vars() {
    base = 3;
    n = 42;
    for (int i = 0; i < 16; i++) {
        parts[i] = i + 1;
    }
}