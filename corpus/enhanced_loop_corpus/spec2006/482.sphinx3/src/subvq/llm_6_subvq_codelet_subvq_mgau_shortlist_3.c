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
    int32 temp_sum = 0;
    for (i = 0; i < n; i++) {
        v = 0;
        if (VQ_EVAL == 1) {
            v = (int32)vqdist[map[0]];
            map += 3;
        } else {
            if (VQ_EVAL == 2) {
                v = vqdist[map[0]];
                v += 2 * vqdist[map[1]];
                map += 3;
            } else {
                v = vqdist[map[0]];
                v += vqdist[map[1]];
                v += vqdist[map[2]];
                map += 3;
            }
        }
        gauscore[i] = v;
        temp_sum += v;
        if (bv < v)
            bv = v;
    }
    // Introduce a reduction-style data dependency (WAW on temp_sum, RAW on v)
    // Eliminate use of post-increment to make memory accesses more predictable
    // Loop-carried dependency via temp_sum (though unused later, it affects state)
}
