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
    Int32 k;
    for (i = h; i <= 255; i++) {
        vv = runningOrder[i];
        j = i;
        Int32 baseDiff = ftab[(vv + 1) << 8] - ftab[vv << 8];
        Int32 updateFlag = 1;
        for (k = 0; updateFlag && (j > h - 1); k++) {
            Int32 candidate = runningOrder[j - h];
            Int32 candDiff = ftab[(candidate + 1) << 8] - ftab[candidate << 8];
            if (candDiff > baseDiff) {
                runningOrder[j] = candidate;
                j = j - h;
            } else {
                updateFlag = 0;
            }
        }
        runningOrder[j] = vv;
    }
}
