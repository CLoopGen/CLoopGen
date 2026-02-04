#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * 1024 * 1024 / sizeof(int16_t))

static int16_t internal_buf[ARRAY_SIZE];
static int16_t internal_ref_buf[ARRAY_SIZE];
static int16_t internal_wptr[ARRAY_SIZE];

int16_t *buf = internal_buf;
int16_t *ref_buf = internal_ref_buf;
int16_t *wptr = internal_wptr;

ptrdiff_t dpitch = 1024;
ptrdiff_t pitch = 1024;

int i = 0;
int j = 0;

void init_vars() {
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        internal_buf[idx] = rand() % 256;
        internal_ref_buf[idx] = rand() % 256;
        internal_wptr[idx] = rand() % 256;
    }
}