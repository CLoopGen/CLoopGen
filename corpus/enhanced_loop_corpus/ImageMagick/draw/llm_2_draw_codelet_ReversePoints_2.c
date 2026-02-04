#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern PointInfo *points;
extern  size_t number_points;
extern PointInfo point;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant reverses the array in strides of 2, processing every second element
    for (i = 0; i < (number_points >> 1); i += 2) {
        if (i + 1 < (number_points >> 1)) {
            // Swap elements at index i and its mirror
            point = points[i];
            points[i] = points[number_points - (i + 1)];
            points[number_points - (i + 1)] = point;

            // Swap elements at index i+1 and its mirror
            point = points[i + 1];
            points[i + 1] = points[number_points - (i + 2)];
            points[number_points - (i + 2)] = point;
        } else {
            // Handle remaining single element if stride steps over
            point = points[i];
            points[i] = points[number_points - (i + 1)];
            points[number_points - (i + 1)] = point;
        }
    }
}
