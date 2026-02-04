#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE_MB 64
#define TOTAL_SIZE (DATA_SIZE_MB * 1024 * 1024)

void **pt;
void *tt[8];
int i;

static void *data_pool;

void init_vars() {
    data_pool = calloc(TOTAL_SIZE, 1);
    if (!data_pool) {
        exit(1);
    }

    pt = malloc(8 * sizeof(void *));
    if (!pt) {
        exit(1);
    }

    for (int idx = 0; idx < 8; idx++) {
        tt[idx] = (char *)data_pool + idx * (TOTAL_SIZE / 8);
    }

    for (int idx = 0; idx < 8; idx++) {
        pt[idx] = (char *)data_pool + (idx + 8) * (TOTAL_SIZE / 16);
    }
}