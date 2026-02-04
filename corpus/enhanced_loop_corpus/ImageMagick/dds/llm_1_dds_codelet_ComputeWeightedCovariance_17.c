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
    if (count > 0) {
        i = 0;
        for (; i < count; i += 2) {
            total += points[i].w;
            centroid.x += (points[i].x * points[i].w);
            centroid.y += (points[i].y * points[i].w);
            centroid.z += (points[i].z * points[i].w);

            if (i + 1 < count) {
                total += points[i+1].w;
                centroid.x += (points[i+1].x * points[i+1].w);
                centroid.y += (points[i+1].y * points[i+1].w);
                centroid.z += (points[i+1].z * points[i+1].w);
            }
        }
    }
}
