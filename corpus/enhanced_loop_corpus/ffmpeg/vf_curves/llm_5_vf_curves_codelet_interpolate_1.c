#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct keypoint {
    double x;
    double y;
    struct keypoint *next;
};


extern  struct keypoint *points;
extern int i;
extern  struct keypoint *point;
extern double xprev;
extern double *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (point = points; point; point = point->next) {
        if (i == -1) {
            xprev = point->x;
            i++;
            continue;
        }
        h[i] = point->x - xprev;
        xprev = point->x;
        i++;
    }
}
