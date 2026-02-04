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
        int swapped = 1;
        for (; swapped && j >= h; ) {
            swapped = 0;
            if ((ftab[((runningOrder[j - h]) + 1) << 8] - ftab[(runningOrder[j - h]) << 8]) > (ftab[((vv) + 1) << 8] - ftab[(vv) << 8])) {
                runningOrder[j] = runningOrder[j - h];
                j -= h;
                swapped = 1;
            }
        }
        runningOrder[j] = vv;
    }
}
