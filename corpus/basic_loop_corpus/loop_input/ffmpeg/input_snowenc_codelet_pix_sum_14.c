#include <stdint.h>
#include <stdlib.h>

uint8_t *pix;
int line_size;
int w;
int h;
int s;
int i;
int j;

void init_vars() {
    w = 1024;
    h = 1024;
    line_size = w;
    s = 0;
    i = 0;
    j = 0;

    uint8_t *data = (uint8_t *)malloc(w * h * sizeof(uint8_t));
    if (!data) exit(1);
    for (int idx = 0; idx < w * h; idx++) {
        data[idx] = rand() & 0xFF;
    }
    pix = data;
}