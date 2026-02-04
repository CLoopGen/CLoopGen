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
    Int32 local_order[256];
    for (i = 0; i < 256; i++) {
        local_order[i] = runningOrder[i];
    }
    for (i = h; i <= 255; i++) {
        vv = local_order[i];
        Int32 key_diff = ftab[(vv + 1) << 8] - ftab[vv << 8];
        j = i;
        for (Int32 k = j - h; j >= h && (ftab[(local_order[k] + 1) << 8] - ftab[local_order[k] << 8]) > key_diff; ) {
            local_order[j] = local_order[k];
            j -= h;
            k = j - h;
        }
        local_order[j] = vv;
    }
    for (i = h; i <= 255; i++) {
        runningOrder[i] = local_order[i];
    }
}
