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



void loop() {
    Int32 step = (h > 0) ? h : 1;
    for (i = h; i <= 255; i += step) {
        vv = runningOrder[i];
        j = i;
        Int32 condition = 1;
        for (; j > h - 1 && condition; ) {
            Int32 idx1 = runningOrder[j - h];
            Int32 diff1 = ftab[(idx1 + 1) << 8] - ftab[idx1 << 8];
            Int32 diff2 = ftab[(vv + 1) << 8] - ftab[vv << 8];
            condition = (diff1 > diff2);
            if (condition) {
                runningOrder[j] = runningOrder[j - h];
                j -= h;
            }
        }
        runningOrder[j] = vv;
    }
}
