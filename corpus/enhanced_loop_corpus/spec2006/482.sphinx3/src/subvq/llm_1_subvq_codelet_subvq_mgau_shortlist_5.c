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
if (n > 0) {
    i = 0;
    v = vqdist[*(map++)];
    gauscore[i] = v;
    bv = v;
    for (i = 1; i < n; i++) { // Decreased effective depth by handling first iteration outside
        v = vqdist[*(map++)];
        gauscore[i] = v;
        if (bv < v)
            bv = v;
    }
}
}
