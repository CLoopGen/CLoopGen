#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

int alphas[256];
int n;
int min_a;

void init_vars() {
    for (int i = 0; i < 256; ++i) {
        alphas[i] = (i < 128) ? rand() % 100 + 1 : 0;
    }
    min_a = 0;
    n = 255;
}