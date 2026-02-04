#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

AVInteger a;
AVInteger b;
AVInteger out;
int i;
int j;
int na = 8;
int nb = 7;

void init_vars() {
    for (int idx = 0; idx < 8; idx++) {
        a.v[idx] = (uint16_t)(idx + 1) * 31;
        b.v[idx] = (uint16_t)(idx + 1) * 47;
        out.v[idx] = 0;
    }
    i = 0;
    j = 0;
}