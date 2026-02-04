#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int *last;
int *Y;
int Ystride;

const int array_size = 64 * 1024 * 1024 / sizeof(int); // ~256MB total data

static int last_buffer[4];
static int Y_buffer[array_size];

void init_vars() {
    i = 0;
    Ystride = (array_size - 3) / 3; // ensures i + Ystride * 3 < array_size when i < 4
    last = last_buffer;
    Y = Y_buffer;
}