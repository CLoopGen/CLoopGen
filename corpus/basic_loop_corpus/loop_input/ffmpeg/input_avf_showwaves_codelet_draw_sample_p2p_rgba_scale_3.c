#include <stdint.h>
#include <stdlib.h>

uint8_t *buf;
int linesize;
uint8_t color[4];
int k;
int start;
int end;

void init_vars() {
    linesize = 1024;
    start = 0;
    end = 262144; // Ensures buf size is about 256MB: (end - start) * linesize ≈ 262144 * 1024 = 268,435,456 bytes
    color[0] = 1;
    color[1] = 2;
    color[2] = 3;
    color[3] = 4;

    buf = (uint8_t*)calloc(end, linesize);
    if (!buf) exit(1);
}