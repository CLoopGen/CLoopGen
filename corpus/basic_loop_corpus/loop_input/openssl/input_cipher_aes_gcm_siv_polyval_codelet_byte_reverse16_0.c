#include <stdint.h>
#include <string.h>

uint8_t *out;
uint8_t *in;
int i;

static uint8_t in_buffer[1024 * 128];
static uint8_t out_buffer[1024 * 128];

void init_vars() {
    in = in_buffer;
    out = out_buffer;
    i = 0;
    memset(in_buffer, 0xAA, sizeof(in_buffer));
    memset(out_buffer, 0x00, sizeof(out_buffer));
}