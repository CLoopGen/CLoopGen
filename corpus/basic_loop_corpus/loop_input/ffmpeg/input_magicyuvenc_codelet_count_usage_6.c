#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct PTable {
    int value;
    int64_t prob;
} PTable;

uint8_t *src;
int width;
int height;
PTable *counts;
int i;
int j;

void init_vars() {
    width = 1024;
    height = 256;
    size_t total_size = (size_t)width * height;
    src = (uint8_t*)calloc(total_size, sizeof(uint8_t));
    if (!src) exit(1);

    counts = (PTable*)calloc(256, sizeof(PTable));
    if (!counts) exit(1);

    for (int idx = 0; idx < 256; idx++) {
        counts[idx].value = idx;
        counts[idx].prob = 0;
    }
}