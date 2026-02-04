#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nal_length_size = 4;
uint8_t *buf;
int buf_index_val;
int *buf_index = &buf_index_val;
int i;
unsigned int nalsize = 0;

void init_vars() {
    const size_t data_size = 1 << 20;
    buf = malloc(data_size);
    if (!buf) {
        exit(1);
    }
    for (size_t j = 0; j < data_size; j++) {
        buf[j] = rand() & 0xFF;
    }
    buf_index_val = 0;
    nal_length_size = 4;
}