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
    struct keypoint *temp = points;
    double prev_x = xprev;
    int idx = i;
    while (temp) {
        if (idx != -1)
            h[idx] = temp->x - prev_x;
        prev_x = temp->x;
        idx++;
        temp = temp->next;
    }
    xprev = prev_x;
    i = idx;
}
