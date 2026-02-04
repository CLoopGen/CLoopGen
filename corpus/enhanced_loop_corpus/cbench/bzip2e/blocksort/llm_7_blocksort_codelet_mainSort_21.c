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
    Int32 local_order[256];
    for (i = 0; i < 256; i++) {
        local_order[i] = runningOrder[i];
    }
    for (i = h; i <= 255; i++) {
        vv = local_order[i];
        Int32 base_diff = ftab[(vv + 1) << 8] - ftab[vv << 8];
        Int32 pos = i;
        Int32 prev_index = pos - h;
        for (; prev_index >= h - 1 && 
                (ftab[(local_order[prev_index] + 1) << 8] - ftab[local_order[prev_index] << 8]) > base_diff; 
                prev_index -= h, pos -= h) {
            local_order[pos] = local_order[prev_index];
        }
        if (pos >= h) {
            local_order[pos] = vv;
        } else {
            local_order[h - 1] = vv;
        }
    }
    for (i = h; i <= 255; i++) {
        runningOrder[i] = local_order[i];
    }
}
