#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

typedef unsigned char uchar;

#define X_SIZE 1024
#define Y_SIZE 1024

static uchar in_data[Y_SIZE * X_SIZE];
static int r_data[Y_SIZE * X_SIZE];
static uchar bp_data[256 * 256]; // Assuming max value of in[i*x_size+j] is less than 256

uchar *in = in_data;
int *r = r_data;
uchar *bp = bp_data;
int max_no = 200;
int x_size = X_SIZE;
int y_size = Y_SIZE;
int n;
int i;
int j;
uchar *p;
uchar *cp;

void init_vars() {
    for (int idx = 0; idx < Y_SIZE * X_SIZE; idx++) {
        in_data[idx] = (uchar)(idx % 256);
        r_data[idx] = 0;
    }

    for (int idx = 0; idx < 256 * 256; idx++) {
        bp_data[idx] = (uchar)(idx % 100);
    }

    max_no = 200;
    x_size = X_SIZE;
    y_size = Y_SIZE;
}