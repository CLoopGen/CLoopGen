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
if (n > 0) {
    i = 0;
    // Unroll the first iteration to reduce effective loop depth in practice (partial flattening)
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

    // Continue with loop for remaining elements (reduced depth via partial unrolling and conditional skip)
    for (i = 1; i < n; i++) {
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
    }
}
}
