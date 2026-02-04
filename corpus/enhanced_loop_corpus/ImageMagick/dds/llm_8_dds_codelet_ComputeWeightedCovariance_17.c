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
extern DDSVector3 centroid;
extern float total;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    total = 0.0f;
    centroid.x = 0.0f;
    centroid.y = 0.0f;
    centroid.z = 0.0f;
    size_t step = 1;
    for (i = 0; i < count; i += step) {
        float wx = points[i].x * points[i].w;
        float wy = points[i].y * points[i].w;
        float wz = points[i].z * points[i].w;
        total += points[i].w;
        centroid.x += wx;
        centroid.y += wy;
        centroid.z += wz;
    }
}
