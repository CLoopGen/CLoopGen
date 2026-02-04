#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t ilbc_state[8] = {1000, -500, 2000, -1500, 3000, -2500, 4000, -3500};

int16_t len = 65536;

int k;

int16_t maxVal = 12345;

static int16_t tmp1_buffer[65536];
static int16_t tmp2_buffer[65536];

int16_t *tmp1 = tmp1_buffer;
int16_t *tmp2 = tmp2_buffer + 65535;

void init_vars() {
    for (int i = 0; i < 65536; i++) {
        tmp1_buffer[i] = 0;
        tmp2_buffer[i] = rand() % 8;
    }
}