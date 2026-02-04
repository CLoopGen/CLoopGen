#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

int16_t **out;
int16_t **in;
int *coeffp;
integer len;
int i;

static int16_t* alloc_2d_int16(int rows, int cols) {
    int16_t* data = calloc(rows * cols, sizeof(int16_t));
    return data;
}

static int16_t** make_2d_int16_array(int rows, int cols) {
    int16_t** arr = malloc(rows * sizeof(int16_t*));
    int16_t* data = alloc_2d_int16(rows, cols);
    for (int i = 0; i < rows; i++) {
        arr[i] = &data[i * cols];
    }
    return arr;
}

void init_vars() {
    len = 131072;

    in = make_2d_int16_array(8, len);
    out = make_2d_int16_array(2, len);
    coeffp = malloc(16 * sizeof(int));

    for (int i = 0; i < 16; i++) {
        coeffp[i] = (i % 7) + 1;
    }

    for (int j = 0; j < len; j++) {
        in[0][j] = (int16_t)(j % 512);
        in[1][j] = (int16_t)(j % 513);
        in[2][j] = (int16_t)(j % 514);
        in[3][j] = (int16_t)(j % 515);
        in[4][j] = (int16_t)(j % 516);
        in[5][j] = (int16_t)(j % 517);
        in[6][j] = (int16_t)(j % 518);
        in[7][j] = (int16_t)(j % 519);
    }

    for (int j = 0; j < len; j++) {
        out[0][j] = 0;
        out[1][j] = 0;
    }

    i = 0;
}