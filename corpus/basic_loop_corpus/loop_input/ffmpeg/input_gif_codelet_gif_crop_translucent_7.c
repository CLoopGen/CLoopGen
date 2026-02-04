#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int linesize;
int *y_start;
int trans;
int x_end;
int y_end;
int is_trans;

void init_vars() {
    linesize = 4096;
    x_end = linesize - 1;
    y_end = 65536;
    trans = 42;
    is_trans = 1;

    buf = (uint8_t*)calloc(y_end, linesize);
    if (!buf) exit(1);

    for (int i = 0; i < y_end; i++) {
        buf[linesize * i + x_end] = trans;
    }

    int start_value = y_end / 2;
    y_start = (int*)malloc(sizeof(int));
    if (!y_start) exit(1);
    *y_start = start_value;
}