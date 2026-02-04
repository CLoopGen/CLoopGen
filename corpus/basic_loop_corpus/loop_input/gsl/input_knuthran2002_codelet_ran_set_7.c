#include <stdlib.h>
#include <stddef.h>

long x[199];
int j;

void init_vars() {
    for (int i = 0; i < 199; i++) {
        x[i] = i * 17;
    }
    j = 99;
}