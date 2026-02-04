#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t * ordprev;
size_t * ordprevbackup;
size_t i;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(size_t))  // ~64MB of data to target ~0.01s runtime

static size_t ordprev_data[DATA_SIZE];
static size_t ordprevbackup_data[DATA_SIZE];

void init_vars() {
    ordprev = ordprev_data;
    ordprevbackup = ordprevbackup_data;
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        ordprevbackup_data[idx] = idx ^ 0xdeadbeef;
    }
}