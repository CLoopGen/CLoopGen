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
for (i = 0; i < n; i++) {
    int32 idx1 = map[2*i];
    int32 idx2 = map[2*i + 1];
    v = vqdist[idx1] + vqdist[idx2];
    gauscore[i] = v;
    if (bv < v)
        bv = v;
}
}
