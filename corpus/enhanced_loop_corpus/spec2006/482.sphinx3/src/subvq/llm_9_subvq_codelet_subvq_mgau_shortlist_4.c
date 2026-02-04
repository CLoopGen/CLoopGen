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
    v = vqdist[*(map++)] + vqdist[*(map++)];
    v += v >> 2;  // Additional arithmetic to increase computational intensity
    gauscore[i] = v * 3;  // More operations per iteration
    if (bv < v)
        bv = v;
}
}
