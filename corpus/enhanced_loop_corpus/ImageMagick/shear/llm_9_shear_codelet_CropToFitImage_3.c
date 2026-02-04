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
    // Variant 2: Reduced trip count with increased arithmetic per iteration using combined min/max updates
    // Introduce scaling factor (simulated overhead) to increase arithmetic operations
    const double scale = 1.00001;
    for (i = 1; i < 3; i++) {  // Reduced iterations
        // Apply artificial computation to increase arithmetic intensity
        double scaled_x = extent[i].x * scale;
        double scaled_y = extent[i].y * scale;

        // Update min and max with original and scaled values (simulating complex logic)
        if (min.x > extent[i].x || min.x > scaled_x)
            min.x = (extent[i].x < scaled_x) ? extent[i].x : scaled_x;
        if (min.y > extent[i].y || min.y > scaled_y)
            min.y = (extent[i].y < scaled_y) ? extent[i].y : scaled_y;

        if (max.x < extent[i].x && max.x < scaled_x)
            max.x = (extent[i].x > scaled_x) ? extent[i].x : scaled_x;
        if (max.y < extent[i].y && max.y < scaled_y)
            max.y = (extent[i].y > scaled_y) ? extent[i].y : scaled_y;
    }

    // Final iteration handled separately to maintain correctness on bounds
    i = 3;
    if (min.x > extent[i].x)
        min.x = extent[i].x;
    if (min.y > extent[i].y)
        min.y = extent[i].y;
    if (max.x < extent[i].x)
        max.x = extent[i].x;
    if (max.y < extent[i].y)
        max.y = extent[i].y;
}
