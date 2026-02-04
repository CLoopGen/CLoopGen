#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

uchar *in;
uchar *mid;
int x_size;
int y_size;
int i;
uchar *midp;

static uchar *in_buffer;
static uchar *mid_buffer;

void init_vars() {
    x_size = 1024;
    y_size = 1024;
    size_t total_size = x_size * y_size;

    in_buffer = (uchar*)calloc(total_size, sizeof(uchar));
    mid_buffer = (uchar*)calloc(total_size, sizeof(uchar));

    in = in_buffer;
    mid = mid_buffer;
    midp = mid;

    for (size_t idx = 0; idx < total_size; idx++) {
        mid_buffer[idx] = (uchar)(idx % 16);
    }
}