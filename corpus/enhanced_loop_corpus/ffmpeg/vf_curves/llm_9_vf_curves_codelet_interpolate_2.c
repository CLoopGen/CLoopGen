#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct keypoint {
    double x;
    double y;
    struct keypoint *next;
};


extern int i;
extern  struct keypoint *point;
extern double *h;
extern double *r;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 1; i < n - 1; i++) {
        const double yp = point->y;
        const double yc = point->next->y;
        const double yn = point->next->next->y;
        const double hc = h[i];
        const double hp = h[i - 1];
        const double diff1 = (yn - yc) / hc;
        const double diff2 = (yc - yp) / hp;
        const double curvature = diff1 - diff2;
        r[i] = 6.0 * curvature;
        point = point->next;
    }
}
