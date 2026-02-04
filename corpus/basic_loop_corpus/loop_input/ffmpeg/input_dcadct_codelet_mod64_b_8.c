#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *input;
int *output;
int i;
int k;

static int input_buf[32];
static int output_buf[32];

void init_vars() {
    input = input_buf;
    output = output_buf;

    for (int idx = 0; idx < 32; idx++) {
        input[idx] = rand() % 1000;
        output[idx] = 0;
    }
}