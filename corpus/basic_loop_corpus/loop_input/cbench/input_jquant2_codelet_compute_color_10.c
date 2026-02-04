#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned short UINT16;

typedef UINT16 histcell;

typedef histcell hist1d[32];

typedef hist1d *hist2d;

typedef hist2d *hist3d;

typedef histcell *histptr;

hist3d histogram;
histptr histp;
int c0;
int c1;
int c2;
int c0min;
int c0max;
int c1min;
int c1max;
int c2min;
int c2max;
long count;
long total;
long c0total;
long c1total;
long c2total;

void init_vars() {
    const int size_c0 = 512;
    const int size_c1 = 512;
    const int size_c2 = 32;

    c0min = 0;
    c0max = size_c0 - 1;
    c1min = 0;
    c1max = size_c1 - 1;
    c2min = 0;
    c2max = size_c2 - 1;

    histogram = (hist3d) calloc(size_c0, sizeof(hist2d));
    if (!histogram) exit(1);

    for (int i = 0; i < size_c0; i++) {
        histogram[i] = (hist2d) calloc(size_c1, sizeof(hist1d));
        if (!histogram[i]) exit(1);
        for (int j = 0; j < size_c1; j++) {
            for (int k = 0; k < size_c2; k++) {
                histogram[i][j][k] = (UINT16)(rand() % 2); 
            }
        }
    }

    total = 0;
    c0total = 0;
    c1total = 0;
    c2total = 0;
}