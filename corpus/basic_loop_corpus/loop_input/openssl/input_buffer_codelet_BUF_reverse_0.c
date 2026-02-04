#include <stdint.h>
#include <stdlib.h>

unsigned char *out;
unsigned char *in;
size_t size;
size_t i;

static unsigned char in_buffer[1024 * 128];
static unsigned char out_buffer[1024 * 128];

void init_vars() {
    size = sizeof(in_buffer);
    in = in_buffer;
    out = &out_buffer[size - 1];
}