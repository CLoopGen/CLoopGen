#include <stdint.h>
#include <stdlib.h>

uint8_t *buf;
int linesize;
uint8_t color[4];
int k;
int start;
int end;

void init_vars() {
    linesize = 64;
    start = 0;
    end = 2 * 1024 * 1024 / linesize;
    color[0] = 1;
    color[1] = 2;
    color[2] = 3;
    color[3] = 4;

    size_t buf_size = (size_t)end * linesize;
    buf = aligned_alloc(32, buf_size);
}