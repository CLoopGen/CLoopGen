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
    for (i = 0; i < count; i++) {
        float w = points[i].w;
        total += w;
        centroid.x += points[i].x * w;
        centroid.y += points[i].y * w;
        centroid.z += points[i].z * w;
        
        if (i + 1 < count) {
            w = points[i + 1].w;
            total += w;
            centroid.x += points[i + 1].x * w;
            centroid.y += points[i + 1].y * w;
            centroid.z += points[i + 1].z * w;
            i++;
        }
    }
}
