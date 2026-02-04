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
    const int idx_prev = i - 1;
    const int idx_curr = i;
    struct keypoint* curr_point = point;
    const double yp = curr_point->y;
    const double yc = curr_point->next->y;
    const double yn = curr_point->next->next->y;
    r[idx_curr] = 6 * ((yn - yc) / h[idx_curr] - (yc - yp) / h[idx_prev]);
    point = point->next;
}
}
