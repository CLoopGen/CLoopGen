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
    float temp_total = total;
    DDSVector3 temp_centroid = centroid;
    
    for (i = 0; i < count; i++) {
        float w = points[i].w;
        temp_total += w;
        temp_centroid.x = temp_centroid.x + (points[i].x * w);
        temp_centroid.y = temp_centroid.y + (points[i].y * w);
        temp_centroid.z = temp_centroid.z + (points[i].z * w);
    }
    
    total = temp_total;
    centroid = temp_centroid;
}
