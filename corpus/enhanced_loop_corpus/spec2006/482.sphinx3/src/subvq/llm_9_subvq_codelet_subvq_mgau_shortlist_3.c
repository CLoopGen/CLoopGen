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
for (i = 0; i < n; i++) {
    v = 0;
    if (VQ_EVAL >= 1) {
        int32 idx = *(map++);
        v = vqdist[idx] + (vqdist[idx] >> 1);  // Add 1.5 * value using bit shift
    }
    if (VQ_EVAL >= 2) {
        v += vqdist[*(map++)];
    }
    if (VQ_EVAL >= 3) {
        v += vqdist[*(map++)];
    }
    gauscore[i] = v;
    if (bv < v)
        bv = v;
}
}
