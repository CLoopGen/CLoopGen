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
    int32 temp_v;
    for (i = 0; i < n; i++) {
        temp_v = vqdist[*(map + i)];
        gauscore[i] = temp_v;
        if (bv < temp_v)
            bv = temp_v;
    }
}
