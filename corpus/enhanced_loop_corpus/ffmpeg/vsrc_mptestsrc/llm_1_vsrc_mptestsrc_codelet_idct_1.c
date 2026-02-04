#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double c[64];
extern int src[64];
extern int i;
extern int j;
extern int k;
extern double tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    for (k = 0; k < 8; k++) {
        double r = c[k * 8 + 0] * src[8 * i + k];
        double s = c[k * 8 + 1] * src[8 * i + k];
        double t = c[k * 8 + 2] * src[8 * i + k];
        double u = c[k * 8 + 3] * src[8 * i + k];
        double v = c[k * 8 + 4] * src[8 * i + k];
        double w = c[k * 8 + 5] * src[8 * i + k];
        double x = c[k * 8 + 6] * src[8 * i + k];
        double y = c[k * 8 + 7] * src[8 * i + k];
        tmp[8 * i + 0] += r;
        tmp[8 * i + 1] += s;
        tmp[8 * i + 2] += t;
        tmp[8 * i + 3] += u;
        tmp[8 * i + 4] += v;
        tmp[8 * i + 5] += w;
        tmp[8 * i + 6] += x;
        tmp[8 * i + 7] += y;
    }
}
}
