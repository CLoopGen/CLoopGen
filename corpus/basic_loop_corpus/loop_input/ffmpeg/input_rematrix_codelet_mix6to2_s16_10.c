#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef int integer;

int16_t **out;
int16_t **in;
int *coeffp;
integer len;
int i;

static int16_t *in_data[6];
static int16_t *out_data[2];
static int coeff_data[12]; // 2 rows * 6 columns

void init_vars() {
    len = 131072; // ~1.3MB input data: 6 input ch * len * sizeof(int16_t)

    // Allocate coefficient array
    for (int idx = 0; idx < 12; idx++) {
        coeff_data[idx] = (idx % 7) * 543; // arbitrary non-zero values
    }
    coeffp = coeff_data;

    // Allocate input and output channel buffers
    for (int ch = 0; ch < 6; ch++) {
        in_data[ch] = (int16_t*)calloc(len, sizeof(int16_t));
        if (!in_data[ch]) exit(1);
        // Initialize with non-zero pattern to aid debugging
        for (int j = 0; j < len; j++) {
            in_data[ch][j] = (j + ch) & 0x1FF;
        }
    }
    in = in_data;

    for (int ch = 0; ch < 2; ch++) {
        out_data[ch] = (int16_t*)calloc(len, sizeof(int16_t));
        if (!out_data[ch]) exit(1);
    }
    out = out_data;

    i = 0;
}