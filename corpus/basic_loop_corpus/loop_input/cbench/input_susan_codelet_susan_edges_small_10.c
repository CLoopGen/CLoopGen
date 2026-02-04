#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
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
    x_size = 1024;
    y_size = 1024;
    max_no = 255;

    in = (uchar*)calloc(x_size * y_size, sizeof(uchar));
    r = (int*)calloc(x_size * y_size, sizeof(int));
    bp = (uchar*)malloc((max_no + 1) * sizeof(uchar));

    for (int idx = 0; idx <= max_no; idx++) {
        bp[idx] = idx % 64;
    }

    for (int idx = 0; idx < x_size * y_size; idx++) {
        in[idx] = rand() % (max_no + 1);
    }
}