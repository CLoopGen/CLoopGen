#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;
extern Int32 j;
extern Int32 runningOrder[256];
extern Int32 vv;
extern Int32 h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = h; i <= 255; i++) {
    vv = runningOrder[i];
    j = i;
    while (1) {
        if (j <= (h - 1)) break;
        if ((ftab[((runningOrder[j - h]) + 1) << 8] - ftab[(runningOrder[j - h]) << 8]) <= (ftab[((vv) + 1) << 8] - ftab[(vv) << 8]))
            break;
        runningOrder[j] = runningOrder[j - h];
        j = j - h;
    }
    runningOrder[j] = vv;
}
}
