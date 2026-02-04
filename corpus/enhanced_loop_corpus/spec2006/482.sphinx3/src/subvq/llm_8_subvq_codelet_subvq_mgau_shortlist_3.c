#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int VQ_EVAL;
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
    if (VQ_EVAL == 1) {
        v = (int32)vqdist[*map];
        map += 3;
    } else {
        if (VQ_EVAL == 2) {
            v = vqdist[*(map++)];
            v += 2 * vqdist[*map];
            map += 2;
        } else {
            v = vqdist[*(map++)];
            v += vqdist[*(map++)];
            v += vqdist[*(map++)];
        }
    }
    gauscore[i] = v;
    if (bv < v)
        bv = v;
    if (i + 1 < n) {
        gauscore[i+1] = v + 1;
        if (bv < v + 1)
            bv = v + 1;
    }
}
}
