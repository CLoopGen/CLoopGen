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
        for (int32 j = 0; j < 1; j++) { // Artificially increased nesting depth with a single-iteration inner loop
            v = vqdist[*(map++)];
            v += vqdist[*(map++)];
            gauscore[i] = v;
            if (bv < v)
                bv = v;
        }
    }
}
