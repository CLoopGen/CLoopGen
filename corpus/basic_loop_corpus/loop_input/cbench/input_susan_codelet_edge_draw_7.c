#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char uchar;

uchar *in;
uchar *mid;
int x_size;
int y_size;
int i;
uchar *inp;
uchar *midp;

#define TOTAL_SIZE (16 * 1024 * 1024) // ~16MB for ~0.01s runtime estimate

void init_vars() {
    x_size = 4096;
    y_size = TOTAL_SIZE / x_size;
    while (x_size * y_size > TOTAL_SIZE) {
        y_size--;
    }

    in = (uchar*)calloc(x_size * y_size + 2 * x_size + 2, sizeof(uchar));
    mid = (uchar*)calloc(x_size * y_size, sizeof(uchar));

    if (!in || !mid) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < x_size * y_size; i++) {
        mid[i] = (i % 16); 
    }

    inp = in + x_size + 1;
    midp = mid;
}