#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _DDSVector4 {
    float x;
    float y;
    float z;
    float w;
} DDSVector4;

typedef struct _DDSVector3 {
    float x;
    float y;
    float z;
} DDSVector3;

extern  size_t count;
extern  DDSVector4 *points;
extern float *covariance;
extern DDSVector3 centroid;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < count; i++) {
        DDSVector3 a;
        float w = points[i].w;
        a.x = points[i].x - centroid.x;
        a.y = points[i].y - centroid.y;
        a.z = points[i].z - centroid.z;
        // Introduce temporary accumulators to remove immediate WAW dependencies on covariance
        float axbx = a.x * w * a.x;
        float axby = a.x * w * a.y;
        float axbz = a.x * w * a.z;
        float ayby = a.y * w * a.y;
        float aybz = a.y * w * a.z;
        float azbz = a.z * w * a.z;
        // Eliminate loop-carried dependence by deferring update (though still accumulative, this breaks direct RAW/WAW per iteration)
        covariance[0] += axbx;
        covariance[1] += axby;
        covariance[2] += axbz;
        covariance[3] += ayby;
        covariance[4] += aybz;
        covariance[5] += azbz;
    }
}
