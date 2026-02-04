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
    float local_total = 0.0f;
    float local_x = 0.0f;
    float local_y = 0.0f;
    float local_z = 0.0f;
    
    for (i = 0; i < count; i++) {
        float w = points[i].w;
        local_total += w;
        local_x += points[i].x * w;
        local_y += points[i].y * w;
        local_z += points[i].z * w;
    }
    
    total += local_total;
    centroid.x += local_x;
    centroid.y += local_y;
    centroid.z += local_z;
}
