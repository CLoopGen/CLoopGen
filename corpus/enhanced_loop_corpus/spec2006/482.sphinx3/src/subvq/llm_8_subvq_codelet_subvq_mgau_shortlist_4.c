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
for (i = 0; i < n; i += 2) {
    if (i + 1 < n) {
        v = vqdist[*(map++)];
        v += vqdist[*(map++)];
        gauscore[i] = v;
        v = vqdist[*(map++)];
        v += vqdist[*(map++)];
        gauscore[i + 1] = v;
        if (bv < v)
            bv = v;
    } else {
        v = vqdist[*(map++)];
        v += vqdist[*(map++)];
        gauscore[i] = v;
        if (bv < v)
            bv = v;
    }
}
}
