#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *nextband;
int g;

void init_vars() {
    nextband = (uint8_t*)aligned_alloc(32, 128);
    if (!nextband) exit(1);
}

__attribute__((destructor))
static void cleanup() {
    if (nextband) free(nextband);
}