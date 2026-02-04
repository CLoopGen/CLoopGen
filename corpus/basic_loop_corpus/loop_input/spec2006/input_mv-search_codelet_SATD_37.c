#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int *byte_abs;
int *diff;
int k;
int satd;

void init_vars() {
    const size_t data_size = 16;
    const size_t abs_table_size = 256;

    diff = (int*)malloc(data_size * sizeof(int));
    byte_abs = (int*)malloc(abs_table_size * sizeof(int));

    for (size_t i = 0; i < data_size; i++) {
        diff[i] = rand() % abs_table_size;
    }

    for (size_t i = 0; i < abs_table_size; i++) {
        byte_abs[i] = abs((int)(i - 128));
    }

    k = 0;
    satd = 0;
}