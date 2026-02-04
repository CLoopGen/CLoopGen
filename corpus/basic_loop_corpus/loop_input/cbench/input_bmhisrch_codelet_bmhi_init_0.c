#include <stdio.h>
#include <inttypes.h>

int patlen = 100;
int skip[256];
int i;

void init_vars() {
    patlen = 100;
    for (int j = 0; j < 256; ++j) {
        skip[j] = 0;
    }
    i = 0;
}