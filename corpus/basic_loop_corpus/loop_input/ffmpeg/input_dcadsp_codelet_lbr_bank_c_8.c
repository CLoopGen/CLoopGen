#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float output[32][4];
ptrdiff_t len;
float AL1;
float AL2;
int i;

void init_vars() {
    len = 32;
    AL1 = 1.5f;
    AL2 = 0.75f;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 4; j++) {
            output[i][j] = (float)(i * 4 + j);
        }
    }
}