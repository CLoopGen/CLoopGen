#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned char uchar;

uchar *in;
int *r;
uchar *bp;
int max_no = 200;
int x_size;
int y_size;
int i;
int j;
int n;
uchar *p;
uchar *cp;

void init_vars() {
    x_size = 512;
    y_size = 512;

    size_t in_size = x_size * y_size;
    size_t bp_size = 256;
    size_t r_size = x_size * y_size;

    in = (uchar*)calloc(in_size, sizeof(uchar));
    r = (int*)calloc(r_size, sizeof(int));
    bp = (uchar*)calloc(bp_size, sizeof(uchar));

    for (size_t idx = 0; idx < in_size; idx++) {
        in[idx] = rand() % 256;
    }

    for (size_t idx = 0; idx < bp_size; idx++) {
        bp[idx] = rand() % 100;
    }

    max_no = 200;
}