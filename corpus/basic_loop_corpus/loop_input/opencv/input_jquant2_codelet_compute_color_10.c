#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned short UINT16;

typedef UINT16 histcell;

typedef histcell hist1d[32];

typedef hist1d *hist2d;

typedef hist2d *hist3d;

typedef histcell *histptr;

static hist1d **histogram_data;
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

void init_vars() {
    c0min = 0;
    c0max = 255;
    c1min = 0;
    c1max = 255;
    c2min = 0;
    c2max = 31;

    histogram_data = (hist1d **)calloc((c0max - c0min + 1), sizeof(hist1d *));
    for (int i = 0; i <= c0max - c0min; i++) {
        histogram_data[i] = (hist1d *)calloc((c1max - c1min + 1), sizeof(hist1d));
        for (int j = 0; j <= c1max - c1min; j++) {
            for (int k = 0; k < 32; k++) {
                histogram_data[i][j][k] = rand() & 0xFFFF;
            }
        }
    }
    histogram = (hist2d *)&histogram_data[c0min];
    total = 0;
}