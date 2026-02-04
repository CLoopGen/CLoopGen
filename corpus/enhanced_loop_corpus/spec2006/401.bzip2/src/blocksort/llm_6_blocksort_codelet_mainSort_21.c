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
    for (i = h; i <= 255; i++) {
        vv = runningOrder[i];
        j = i;
        Int32 temp_j = j;
        Int32 temp_vv = vv;
        Int32 base_vv = ftab[(temp_vv + 1) << 8] - ftab[temp_vv << 8];
        for (; temp_j > h - 1;) {
            Int32 neighbor = runningOrder[temp_j - h];
            Int32 diff_neighbor = ftab[(neighbor + 1) << 8] - ftab[neighbor << 8];
            if (diff_neighbor <= base_vv) break;
            runningOrder[temp_j] = neighbor;
            temp_j -= h;
        }
        runningOrder[temp_j] = temp_vv;
    }
}
