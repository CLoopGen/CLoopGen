#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 n;
extern int32 *gauscore;
extern int32 *map;
extern int32 i;
extern int32 v;
extern int32 bv;
extern int32 *vqdist;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32 *map_ptr = map;
for (i = 0; i < n; i++) {
    v = vqdist[*map_ptr] + vqdist[*(map_ptr + 1)];
    map_ptr += 2;
    gauscore[i] = v;
    if (bv < v)
        bv = v;
}
}
