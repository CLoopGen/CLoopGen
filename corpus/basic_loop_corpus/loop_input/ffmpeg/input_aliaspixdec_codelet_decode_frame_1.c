#include <stdint.h>
#include <stdlib.h>

int pixel = 42;

uint8_t *out_buf;
uint8_t count = 255;

int i;

static uint8_t *temp_buffer;

void init_vars() {
    temp_buffer = (uint8_t *)calloc(256, sizeof(uint8_t));
    if (!temp_buffer) exit(1);
    out_buf = temp_buffer;
}