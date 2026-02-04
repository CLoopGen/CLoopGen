#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x_stride;
int x_out_max;
int channel;

void init_vars() {
    x_stride = 1024;
    x_out_max = 1 << 20;
    channel = 0;
}