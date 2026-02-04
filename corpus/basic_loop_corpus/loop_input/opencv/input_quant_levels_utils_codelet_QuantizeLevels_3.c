#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int q_level[256];
int min_s;
int max_s;
int s;

void init_vars() {
    min_s = 0;
    max_s = 255;
    for (int i = 0; i < 256; ++i) {
        q_level[i] = rand() % 1000;
    }
}