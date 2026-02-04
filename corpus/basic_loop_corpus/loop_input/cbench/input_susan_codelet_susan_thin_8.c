#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned char uchar;

int *r;
uchar *mid;
int x_size;
int y_size;
int l[9];
int centre;
int b01;
int b12;
int b21;
int b10;
int p1;
int p2;
int p3;
int p4;
int b00;
int b02;
int b20;
int b22;
int m;
int n;
int a;
int b;
int x;
int y;
int i;
int j;
uchar *mp;

void init_vars() {
    x_size = 512;
    y_size = 512;

    size_t total_size = x_size * y_size;
    r = (int*)calloc(total_size, sizeof(int));
    mid = (uchar*)calloc(total_size, sizeof(uchar));

    for (size_t idx = 0; idx < total_size; idx++) {
        r[idx] = rand() % 1000;
        mid[idx] = rand() % 10;
    }

    centre = 0;
    b01 = 0;
    b12 = 0;
    b21 = 0;
    b10 = 0;
    p1 = 0;
    p2 = 0;
    p3 = 0;
    p4 = 0;
    b00 = 0;
    b02 = 0;
    b20 = 0;
    b22 = 0;
    m = 0;
    n = 0;
    a = 0;
    b = 0;
    x = 0;
    y = 0;
    i = 0;
    j = 0;
    mp = mid + (4 - 1) * x_size + 4 - 1;
}