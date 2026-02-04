#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *nextband;
int g;

static uint8_t nextband_data[128];

void init_vars() {
    nextband = nextband_data;
    g = 0;
}