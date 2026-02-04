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
for (size_t outer = 0; outer < count; outer += 8) {
    for (size_t inner = outer; inner < count && inner < outer + 8; ++inner) {
        DDSVector3 a, b;
        a.x = points[inner].x - centroid.x;
        a.y = points[inner].y - centroid.y;
        a.z = points[inner].z - centroid.z;
        b.x = points[inner].w * a.x;
        b.y = points[inner].w * a.y;
        b.z = points[inner].w * a.z;
        covariance[0] += a.x * b.x;
        covariance[1] += a.x * b.y;
        covariance[2] += a.x * b.z;
        covariance[3] += a.y * b.y;
        covariance[4] += a.y * b.z;
        covariance[5] += a.z * b.z;
    }
}
}
