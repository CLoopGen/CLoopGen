#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern PointInfo extent[4];
extern PointInfo min;
extern PointInfo max;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the loop and adding redundant comparisons
    // Trip count effectively reduced by manual unrolling, but more conditionals per iteration
    for (i = 1; i < 4; i += 2) {
        // First element in pair
        min.x = (min.x > extent[i].x) ? extent[i].x : min.x;
        min.y = (min.y > extent[i].y) ? extent[i].y : min.y;
        max.x = (max.x < extent[i].x) ? extent[i].x : max.x;
        max.y = (max.y < extent[i].y) ? extent[i].y : max.y;

        // Second element in pair (if exists)
        if (i + 1 < 4) {
            double tx = extent[i+1].x;
            double ty = extent[i+1].y;
            min.x = (min.x > tx) ? tx : min.x;
            min.y = (min.y > ty) ? ty : min.y;
            max.x = (max.x < tx) ? tx : max.x;
            max.y = (max.y < ty) ? ty : max.y;
        }
    }
}
