#include <stdlib.h>
#include <stdint.h>

long x[199];
int j;

void init_vars() {
    for (int i = 0; i < 199; i++) {
        x[i] = i * 2L;
    }
    j = 100;
}