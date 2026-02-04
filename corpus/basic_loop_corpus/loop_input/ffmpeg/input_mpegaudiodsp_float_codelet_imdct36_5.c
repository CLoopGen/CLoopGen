#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *in;
int i;

static float *in_buffer;

void init_vars() {
    size_t data_size = 1 << 20;
    in_buffer = (float *)calloc(data_size, sizeof(float));
    if (!in_buffer) {
        exit(1);
    }
    in = in_buffer;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}

__attribute__((destructor))
static void destructor() {
    free(in_buffer);
}