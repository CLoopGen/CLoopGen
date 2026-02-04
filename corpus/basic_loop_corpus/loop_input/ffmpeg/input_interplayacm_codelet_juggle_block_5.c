#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int sub_count;
unsigned int sub_len;
unsigned int i;
int *block_p;
int *p;

#define DATA_SIZE (128 << 20) // 128 MB of data
#define ELEMENT_SIZE sizeof(int)
#define ARRAY_ELEMENT_COUNT (DATA_SIZE / ELEMENT_SIZE)

static int *data_array;

void init_vars() {
    sub_len = 64; // stride in units of int
    sub_count = (ARRAY_ELEMENT_COUNT + sub_len - 1) / sub_len;

    data_array = (int *)calloc(ARRAY_ELEMENT_COUNT, ELEMENT_SIZE);
    if (!data_array) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    block_p = data_array;
}