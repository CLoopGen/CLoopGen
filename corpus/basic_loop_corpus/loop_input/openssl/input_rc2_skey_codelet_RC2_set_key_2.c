#include <stdio.h>
#include <inttypes.h>

typedef unsigned int RC2_INT;

int i;
unsigned char *k;
RC2_INT *ki;

#define DATA_SIZE 512 * 1024

static unsigned char k_data[DATA_SIZE];
static RC2_INT ki_data[DATA_SIZE / 2];

void init_vars() {
    k = k_data;
    ki = &ki_data[(DATA_SIZE / 2) - 1];
    for (int idx = 0; idx < DATA_SIZE; ++idx) {
        k_data[idx] = (unsigned char)(idx & 0xFF);
    }
}