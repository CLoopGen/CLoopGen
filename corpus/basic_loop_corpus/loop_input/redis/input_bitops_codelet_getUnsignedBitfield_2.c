#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char *p;
uint64_t offset;
uint64_t bits;
uint64_t byte;
uint64_t bit;
uint64_t byteval;
uint64_t bitval;
uint64_t j;
uint64_t value;

static unsigned char data[1 << 20]; // 1MB of data

void init_vars() {
    for (size_t i = 0; i < sizeof(data); i++) {
        data[i] = rand();
    }
    p = data;
    offset = 0;
    bits = (sizeof(data) * 8) - 1; // Ensure we don't go out of bounds on last access
    byte = 0;
    bit = 0;
    byteval = 0;
    bitval = 0;
    j = 0;
    value = 0;
}