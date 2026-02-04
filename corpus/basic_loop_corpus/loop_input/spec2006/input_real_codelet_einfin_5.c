#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

unsigned short *x;
int i;

static unsigned short x_buffer[1048576]; // 2MB buffer (1M elements of unsigned short)

void init_vars() {
    x = x_buffer;
    i = 0;
}