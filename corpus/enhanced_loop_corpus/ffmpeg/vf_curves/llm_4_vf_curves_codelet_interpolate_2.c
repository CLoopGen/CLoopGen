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



void loop(){
for (i = 1; i < n - 1; i++) {
    const double yp = point->y;
    const double yc = point->next->y;
    const double yn = point->next->next->y;
    if (h[i] != 0.0 && h[i - 1] != 0.0) {
        r[i] = 6 * ((yn - yc) / h[i] - (yc - yp) / h[i - 1]);
    } else {
        r[i] = 0.0;
    }
    point = point->next;
}
}
