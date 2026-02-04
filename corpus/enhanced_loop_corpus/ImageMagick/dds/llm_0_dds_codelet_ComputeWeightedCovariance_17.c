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
    for (size_t outer = 0; outer < (count + 3) / 4; outer++) {
        size_t base_idx = outer * 4;
        for (size_t inner = 0; inner < 4; inner++) {
            size_t i = base_idx + inner;
            if (i >= count) break;
            total += points[i].w;
            centroid.x += (points[i].x * points[i].w);
            centroid.y += (points[i].y * points[i].w);
            centroid.z += (points[i].z * points[i].w);
        }
    }
}
