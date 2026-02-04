#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float FLOAT;

FLOAT prescale[64];
int16_t block[64];
FLOAT temp[64];
int i;

void init_vars() {
    for (int j = 0; j < 64; j++) {
        prescale[j] = (FLOAT)(j + 1);
        block[j] = (int16_t)(j % 32768);
        temp[j] = 0.0f;
    }
    i = 0;
}