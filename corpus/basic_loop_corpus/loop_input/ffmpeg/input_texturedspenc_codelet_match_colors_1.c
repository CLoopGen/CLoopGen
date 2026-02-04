#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint32_t mask;
int dots[16];
int x;
int c0_point;
int half_point;
int c3_point;
int indexMap[8];

void init_vars() {
    mask = 0xFFFFFFFFu;
    c0_point = 50;
    half_point = 40;
    c3_point = 60;
    for (int i = 0; i < 16; i++) {
        dots[i] = rand() % 100;
    }
    for (int i = 0; i < 8; i++) {
        indexMap[i] = (i << 24) & 0xFF000000u;
    }
    x = 0;
}