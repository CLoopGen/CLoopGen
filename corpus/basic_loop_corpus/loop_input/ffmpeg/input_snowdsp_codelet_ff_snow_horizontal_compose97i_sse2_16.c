#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

#define DATA_SIZE (128 * 1024 * sizeof(IDWTELEM))
static IDWTELEM b_buffer[DATA_SIZE / sizeof(IDWTELEM)];
static IDWTELEM temp_buffer[DATA_SIZE / sizeof(IDWTELEM)];

IDWTELEM *b = b_buffer;
IDWTELEM *temp = temp_buffer;
int i;

void init_vars() {
    i = (DATA_SIZE / sizeof(IDWTELEM)) - 2;
    while ((i & 62) != 62) {
        i--;
    }
    for (int j = 0; j < DATA_SIZE / sizeof(IDWTELEM); j++) {
        b_buffer[j] = (IDWTELEM)(j & 0xFFFF);
        temp_buffer[j] = (IDWTELEM)((j ^ 0x5555) & 0xFFFF);
    }
}