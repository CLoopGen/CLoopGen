#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned short UINT16;
typedef UINT16 histcell;
typedef histcell hist1d[32];
typedef hist1d *hist2d;
typedef hist2d *hist3d;
typedef histcell *histptr;

histcell ***histogram;
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
long ccount;

void init_vars() {
    c0min = 0;
    c0max = 499; // 500 elements
    c1min = 0;
    c1max = 511; // 512 elements
    c2min = 0;
    c2max = 31;  // Fixed to match hist1d size - 1

    ccount = 0;

    // Allocate histogram: [c0max - c0min + 1][c1max - c1min + 1][32]
    int size_c0 = c0max - c0min + 1;
    int size_c1 = c1max - c1min + 1;

    histogram = (histcell ***)calloc(size_c0, sizeof(histcell **));
    for (int i = 0; i < size_c0; i++) {
        histogram[i] = (histcell **)calloc(size_c1, sizeof(histcell *));
        for (int j = 0; j < size_c1; j++) {
            histogram[i][j] = (histcell *)calloc(32, sizeof(histcell));
            // Randomly initialize some entries to non-zero to simulate realistic access
            for (int k = 0; k < 32; k++) {
                // Approximately 10% non-zero
                histogram[i][j][k] = (rand() % 10 == 0) ? (rand() % 100 + 1) : 0;
            }
        }
    }
}