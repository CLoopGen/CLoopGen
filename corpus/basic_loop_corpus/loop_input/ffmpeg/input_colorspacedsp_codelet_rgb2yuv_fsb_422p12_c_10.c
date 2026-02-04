#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 131072; // ~1MB of data for int (4 bytes each), ensures ~0.01 sec runtime
int x;
int rnd = 0xdeadbeef;

int *rnd_scratch[3][2];

static int buffer_0_0[131072];
static int buffer_0_1[131072];

void init_vars() {
    rnd_scratch[0][0] = buffer_0_0;
    rnd_scratch[0][1] = buffer_0_1;
}