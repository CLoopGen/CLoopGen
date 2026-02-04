#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int i;
int ncol;
uint32_t *pal;

static uint8_t buf_data[192000000]; // ~192 MB to target ~0.01 sec runtime
static uint32_t pal_data[64000000]; // 3:1 expansion from buf (each 3 bytes -> 1 uint32_t)

void init_vars() {
    buf = buf_data;
    pal = pal_data;
    ncol = 64000000; // ensures buf[3*ncol] accesses up to index 191999999, within bounds
    i = 0;
}