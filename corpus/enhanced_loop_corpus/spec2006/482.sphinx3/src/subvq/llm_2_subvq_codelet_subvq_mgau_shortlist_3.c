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
    int32 idx = map[i * 3]; // Use indirect indexing with stride for map access
    if (VQ_EVAL == 1) {
        v = (int32)vqdist[idx];
    } else {
        if (VQ_EVAL == 2) {
            v = vqdist[idx];
            v += 2 * vqdist[map[i * 3 + 1]];
        } else {
            v = vqdist[idx];
            v += vqdist[map[i * 3 + 1]];
            v += vqdist[map[i * 3 + 2]];
        }
    }
    gauscore[i] = v;
    if (bv < v)
        bv = v;
}
}
