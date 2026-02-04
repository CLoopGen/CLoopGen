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
        Int32 temp_vv = vv;
        Int32 k = i;
        for (; (k > h - 1) && 
                (ftab[((runningOrder[k - h]) + 1) << 8] - ftab[(runningOrder[k - h]) << 8]) > 
                (ftab[((temp_vv) + 1) << 8] - ftab[(temp_vv) << 8]); 
                k -= h) {
            runningOrder[k] = runningOrder[k - h];
        }
        runningOrder[k] = temp_vv;
    }
}
