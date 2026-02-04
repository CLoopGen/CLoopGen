#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned short *p;
int i;

static unsigned short p_buffer[1];

void init_vars() {
    p = p_buffer;
}