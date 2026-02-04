#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;

int32_t **out;
int32_t **in;
int *coeffp;
integer len;
int i;

static int32_t* in_data[6];
static int32_t* out_data[2];
static int coeff_data[12]; // 2 * 6 = 12 coefficients

void init_vars() {
    const size_t data_size = 1 << 20; // ~4MB input per channel, total ~24MB
    len = data_size;

    for (int ch = 0; ch < 6; ch++) {
        in_data[ch] = (int32_t*)calloc(len, sizeof(int32_t));
        if (!in_data[ch]) exit(1);
        for (int j = 0; j < len; j++) {
            in_data[ch][j] = rand() % 65536 - 32768;
        }
    }

    for (int ch = 0; ch < 2; ch++) {
        out_data[ch] = (int32_t*)calloc(len, sizeof(int32_t));
        if (!out_data[ch]) exit(1);
    }

    in = in_data;
    out = out_data;

    for (int j = 0; j < 12; j++) {
        coeff_data[j] = rand() % 65536 - 32768;
    }
    coeffp = coeff_data;
}