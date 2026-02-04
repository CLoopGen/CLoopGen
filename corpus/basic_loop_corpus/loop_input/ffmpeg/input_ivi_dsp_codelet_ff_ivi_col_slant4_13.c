#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *in;
int16_t *out;
ptrdiff_t pitch;
uint8_t *flags;
int i;
int row2;
int t0;
int t1;
int t2;
int t3;
int t4;

static int32_t *in_data;
static int16_t *out_data;
static uint8_t *flags_data;

void init_vars() {
    const size_t data_size = 1 << 20;
    in_data = aligned_alloc(32, sizeof(int32_t) * (data_size + 15));
    out_data = aligned_alloc(32, sizeof(int16_t) * (data_size + 15));
    flags_data = aligned_alloc(32, sizeof(uint8_t) * 4);

    for (size_t i = 0; i < data_size + 15; i++) {
        in_data[i] = rand() % 1000 - 500;
        out_data[i] = 0;
    }

    for (int i = 0; i < 4; i++) {
        flags_data[i] = rand() % 2;
    }

    in = in_data;
    out = out_data;
    flags = flags_data;
    pitch = 1;
    row2 = 2;
}