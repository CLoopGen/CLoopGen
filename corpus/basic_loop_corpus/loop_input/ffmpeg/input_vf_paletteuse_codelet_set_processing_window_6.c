#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int y_start = 0;
int y = 0;
int x_end = 127;
int y_end = 1999;
uint32_t *prv_srcp = NULL;
uint32_t *cur_srcp = NULL;
int prv_src_linesize = 128;
int cur_src_linesize = 128;
int same_column = 1;

static uint32_t prv_src_storage[2000 * 128];
static uint32_t cur_src_storage[2000 * 128];

void init_vars() {
    prv_srcp = prv_src_storage;
    cur_srcp = cur_src_storage;

    size_t total_size = sizeof(uint32_t) * 2000 * 128;
    memset(prv_src_storage, 0x55, total_size);
    memset(cur_src_storage, 0x55, total_size);

    for (int i = 0; i < 2000; i++) {
        if (i % 7 == 0) {
            cur_src_storage[i * 128 + x_end] ^= 1;
        }
    }

    y_start = 0;
    y_end = 1999;
    x_end = 127;
    same_column = 1;
}