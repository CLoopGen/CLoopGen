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
for (i = h; i <= 255; i += 2) {
    vv = runningOrder[i];
    j = i;
    if (j > h - 1) {
        Int32 key1 = (ftab[((vv) + 1) << 8] - ftab[(vv) << 8]);
        Int32 idx, cmpVal;
        for (idx = j - h; j > h - 1;) {
            cmpVal = (ftab[((runningOrder[idx]) + 1) << 8] - ftab[(runningOrder[idx]) << 8]);
            if (cmpVal <= key1) break;
            runningOrder[j] = runningOrder[idx];
            j = idx;
            idx -= h;
            if (idx < h - 1) break;
        }
    }
    runningOrder[j] = vv;

    if (i + 1 <= 255) {
        vv = runningOrder[i + 1];
        j = i + 1;
        if (j > h - 1) {
            Int32 key2 = (ftab[((vv) + 1) << 8] - ftab[(vv) << 8]);
            Int32 idx = j - h;
            while (j > h - 1) {
                Int32 cmpVal2 = (ftab[((runningOrder[idx]) + 1) << 8] - ftab[(runningOrder[idx]) << 8]);
                if (cmpVal2 <= key2) break;
                runningOrder[j] = runningOrder[idx];
                j = idx;
                idx -= h;
                if (idx < h - 1) break;
            }
        }
        runningOrder[j] = vv;
    }
}
}
