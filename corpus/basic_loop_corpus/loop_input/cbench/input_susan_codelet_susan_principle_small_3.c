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

static uchar in_data[1 << 20];
static int r_data[1 << 20];
static uchar bp_data[512];

void init_vars() {
    x_size = 1024;
    y_size = 1024;
    max_no = 256;

    in = in_data;
    r = r_data;
    bp = bp_data;

    for (int idx = 0; idx < (1 << 20); idx++) {
        in_data[idx] = rand() % 256;
    }

    for (int idx = 0; idx < 512; idx++) {
        bp_data[idx] = rand() % 256;
    }

    memset(r_data, 0, sizeof(r_data));
}