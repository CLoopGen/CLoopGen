#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
unsigned int bit_size;
int i;
int num_bytes;
int crc;

static uint8_t *internal_buf;
static unsigned long data_size = 1 << 20; // 1MB for ~0.01 sec runtime estimate

void init_vars() {
    internal_buf = calloc(data_size, sizeof(uint8_t));
    if (!internal_buf) {
        exit(1);
    }

    buf = internal_buf;
    bit_size = 8 * (data_size - 1); // ensures num_bytes is within bounds
    num_bytes = data_size - 1;
    crc = 1; // arbitrary non-zero initial CRC value
}