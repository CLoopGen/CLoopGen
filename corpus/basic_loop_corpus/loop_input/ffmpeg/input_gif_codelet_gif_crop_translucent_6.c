#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int linesize;
int *x_start;
int *y_start;
int trans;
int y_end;
int is_trans;

static uint8_t buf_data[1 << 20]; // 1MB buffer

void init_vars() {
    linesize = 1024;
    x_start = (int*)malloc(sizeof(int));
    y_start = (int*)malloc(sizeof(int));
    *x_start = 0;
    *y_start = 0;
    y_end = 1000;
    trans = 0;
    is_trans = 1;
    buf = buf_data;
    for (int i = 0; i < y_end; ++i) {
        for (int j = 0; j < linesize; ++j) {
            buf[i * linesize + j] = (i == y_end - 1 && j == linesize - 1) ? 1 : 0;
        }
    }
}