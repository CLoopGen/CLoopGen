#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int frequency[512];
uint8_t flag[512];
int up[512];
int j;

void init_vars() {
    for (int i = 0; i < 256; i++) {
        frequency[i] = rand() % 1000 + 1;
        flag[i] = 1;
        up[i] = 0;
    }
    for (int i = 256; i < 512; i++) {
        frequency[i] = 0;
        flag[i] = 0;
        up[i] = 0;
    }
    j = 257;
}