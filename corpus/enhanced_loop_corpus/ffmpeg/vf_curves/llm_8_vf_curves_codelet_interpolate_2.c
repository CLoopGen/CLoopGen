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
    for (i = 2; i < n - 2; i += 2) {
        const double yp = point->y;
        const double yc = point->next->y;
        const double yn = point->next->next->y;
        const double ynn = point->next->next->next->y;
        r[i] = 6 * ((yn - yc) / h[i] - (yc - yp) / h[i - 1]);
        r[i + 1] = 6 * ((ynn - yn) / h[i + 1] - (yn - yc) / h[i]);
        point = point->next->next;
    }
}
