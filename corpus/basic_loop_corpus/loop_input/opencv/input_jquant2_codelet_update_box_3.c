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
int c1min;
int c2min;
int c0max;
int c1max;
int c2max;
long ccount;

void init_vars() {
    c0min = 0;
    c1min = 0;
    c2min = 0;
    
    c0max = 255;
    c1max = 255;
    c2max = 31;
    
    ccount = 0;
    
    size_t total_size = (c0max - c0min + 1) * (c1max - c1min + 1) * sizeof(hist1d *);
    histogram_data = (hist1d **)calloc(total_size, 1);
    
    histogram = (hist2d *)histogram_data;
    
    for (int i = 0; i <= c0max - c0min; i++) {
        histogram_data[i] = (hist1d *)calloc((c1max - c1min + 1), sizeof(hist1d));
        for (int j = 0; j <= c1max - c1min; j++) {
            for (int k = 0; k < 32; k++) {
                histogram_data[i][j][k] = (i * (c1max - c1min + 1) + j) % 17 == 0 ? 1 : 0;
            }
        }
    }
}