#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

typedef unsigned char uchar;

uchar *in;
int *r;
uchar *bp;
int max_no;
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
    max_no = 1000;

    in = (uchar*)calloc(x_size * y_size, sizeof(uchar));
    r = (int*)calloc(x_size * y_size, sizeof(int));
    bp = (uchar*)calloc(256, sizeof(uchar));

    for (int idx = 0; idx < x_size * y_size; idx++) {
        in[idx] = rand() % 256;
    }
    for (int idx = 0; idx < 256; idx++) {
        bp[idx] = rand() % 100;
    }

    i = 0;
    j = 0;
    n = 0;
    p = NULL;
    cp = NULL;
}