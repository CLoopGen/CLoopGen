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
    Int32 temp;
    for (i = h; i <= 255; i++) {
        vv = runningOrder[i];
        j = i;
        temp = vv;
        if (j > h - 1) {
            Int32 prevIndex = j - h;
            Int32 runningPrev = runningOrder[prevIndex];
            UInt32 diffCurrent = ftab[(vv + 1) << 8] - ftab[vv << 8];
            UInt32 diffPrev = ftab[(runningPrev + 1) << 8] - ftab[runningPrev << 8];
            for (; diffPrev > diffCurrent && j > h - 1; ) {
                runningOrder[j] = runningPrev;
                j -= h;
                if (j <= h - 1) break;
                prevIndex = j - h;
                runningPrev = runningOrder[prevIndex];
                diffPrev = ftab[(runningPrev + 1) << 8] - ftab[runningPrev << 8];
            }
        }
        runningOrder[j] = temp;
    }
}
