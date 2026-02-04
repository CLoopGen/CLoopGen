#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern PointInfo first[3];
extern PointInfo last[3];
extern PointInfo point[3];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    PointInfo temp[3];
    for (i = 0; i < 3; i++) {
        temp[i] = point[i];      // Introduce temporary storage (WAW dependency within iteration)
    }
    for (i = 0; i < 3; i++) {
        first[i] = temp[i];      // RAW: depends on previous loop's write to temp[i]
        last[i] = temp[i];       // No loop-carried dependency; independent per element
    }
}
