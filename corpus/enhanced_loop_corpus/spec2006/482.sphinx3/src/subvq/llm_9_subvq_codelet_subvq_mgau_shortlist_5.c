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
    int32 idx = *(map++);
    v = vqdist[idx] + (idx & 0x3); // Added arithmetic: index-dependent offset
    gauscore[i] = v * v; // Squared value increases computation intensity
    if (bv < v)
        bv = v;
}
}
