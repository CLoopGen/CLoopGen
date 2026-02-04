#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *dst;
int i;
int dc0;

static int16_t dst_buffer[1 << 20]; // 2MB buffer for dst (sufficient for 16*16 steps with safety)

void init_vars() {
    dst = dst_buffer;
    i = 0;
    dc0 = 42; 
}