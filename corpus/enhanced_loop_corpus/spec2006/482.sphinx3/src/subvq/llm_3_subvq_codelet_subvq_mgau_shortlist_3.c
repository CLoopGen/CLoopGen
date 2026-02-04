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
// Change to consecutive memory access pattern by pre-loading map indices
int32 *local_map = map;
for (i = 0; i < n; i++) {
    if (VQ_EVAL == 1) {
        v = (int32)vqdist[local_map[0]];
        local_map += 3;
    } else {
        if (VQ_EVAL == 2) {
            v = vqdist[local_map[0]];
            v += 2 * vqdist[local_map[1]];
            local_map += 3;
        } else {
            v = vqdist[local_map[0]];
            v += vqdist[local_map[1]];
            v += vqdist[local_map[2]];
            local_map += 3;
        }
    }
    gauscore[i] = v;
    if (bv < v)
        bv = v;
}
}
