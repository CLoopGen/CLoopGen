#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *in;
int i;

static uint8_t in_buffer[16];

void init_vars() {
    in = in_buffer;
    i = 0;
}