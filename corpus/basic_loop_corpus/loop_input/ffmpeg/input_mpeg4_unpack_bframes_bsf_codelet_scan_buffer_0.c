#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t *buf;
int *pos_p;
uint8_t *end;
uint8_t *pos;

static uint8_t *internal_buf;
static int internal_pos_p;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    internal_buf = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    if (!internal_buf) {
        exit(1);
    }

    buf = internal_buf;
    pos_p = &internal_pos_p;
    pos = internal_buf;
    end = internal_buf + data_size;

    size_t target_offset = data_size / 2;
    internal_buf[target_offset] = 'p';
    internal_buf[target_offset + 1] = '\x00';

    *pos_p = -1;
}