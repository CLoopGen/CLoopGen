#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct PTable {
    int value;
    int64_t prob;
} PTable;

PTable counts[256];
int i;

void init_vars() {
    for (int idx = 0; idx < 256; idx++) {
        counts[idx].value = 0;
        counts[idx].prob = 0;
    }
    i = 0;
}