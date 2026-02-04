#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int i;
int j;
int t;
int16_t *ptr1;
int16_t *ptr2;
int coef;

static int16_t out_buffer[1048576]; // ~2MB output buffer
static int16_t ptr1_buffer[1048576];
static int16_t ptr2_buffer[1048576];

void init_vars() {
    out = out_buffer;
    ptr1 = ptr1_buffer;
    ptr2 = ptr2_buffer;

    i = 0;
    j = 4;
    t = 0;
    coef = 1000;

    for (int idx = 0; idx < 1048576; idx++) {
        ptr1_buffer[idx] = (int16_t)(idx % 500);
        ptr2_buffer[idx] = (int16_t)(idx % 300);
        out_buffer[idx] = 0;
    }
}