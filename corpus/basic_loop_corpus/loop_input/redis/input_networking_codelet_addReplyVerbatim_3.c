#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *ext;
char *p;

static char ext_buffer[4] = {'a', 'b', 'c', '\x00'};
static char p_buffer[3];

void init_vars() {
    ext = ext_buffer;
    p = p_buffer;
}