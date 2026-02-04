#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char *data;
int i;
int j;
unsigned char c[3];
uint32_t *palette;

static unsigned char data_buffer[768]; // 256 * 3 = 768 bytes for safe access
static uint32_t palette_buffer[256];

void init_vars() {
    data = data_buffer;
    palette = palette_buffer;
    i = 0;
    j = 0;
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;

    for (int idx = 0; idx < 768; idx++) {
        data_buffer[idx] = (unsigned char)(idx * 31); // Arbitrary initialization
    }
}