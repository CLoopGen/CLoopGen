#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

char **argv;
int bottom;
int middle;
int top;
char *tem;
int len;
int i;

#define NUM_PTRS (1 << 20)

char *data_block;
char **ptr_array;

void init_vars() {
    int segment_length = middle - bottom;
    len = segment_length;

    data_block = malloc(NUM_PTRS * sizeof(char));
    ptr_array = malloc(NUM_PTRS * sizeof(char*));

    for (int j = 0; j < NUM_PTRS; j++) {
        data_block[j] = 'A' + (j % 26);
        ptr_array[j] = &data_block[j];
    }

    argv = ptr_array;

    bottom = NUM_PTRS / 4;
    middle = NUM_PTRS / 2;
    top = NUM_PTRS - (middle - bottom) - 1;

    segment_length = middle - bottom;
    len = segment_length;

    if (bottom + len > NUM_PTRS || top - (middle - bottom) + len >= NUM_PTRS) {
        len = NUM_PTRS - (top - (middle - bottom)) - 1;
    }

    if (len <= 0) {
        len = 1;
    }
}