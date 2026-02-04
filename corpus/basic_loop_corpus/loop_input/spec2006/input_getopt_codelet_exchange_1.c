#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **argv;
int bottom;
int middle;
char *tem;
int len;
int i;

#define DATA_SIZE (1 << 20)  // 1MB of data: 2^20 elements

static char *data_block;
static char **ptr_array;

void init_vars() {
    bottom = 0;
    middle = (DATA_SIZE / sizeof(char*)) / 2;
    len = middle;  // ensures bottom + len and middle + len are valid
    tem = NULL;

    data_block = calloc(DATA_SIZE, 1);
    if (!data_block) exit(1);

    ptr_array = (char**)data_block;

    argv = ptr_array;

    for (int idx = 0; idx < (DATA_SIZE / sizeof(char*)); idx++) {
        ptr_array[idx] = (char*)&data_block[idx * sizeof(char*)];
    }
}