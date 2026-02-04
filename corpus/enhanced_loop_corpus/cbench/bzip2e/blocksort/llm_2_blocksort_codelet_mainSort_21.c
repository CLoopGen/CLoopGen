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
        Int32 key_ftab_diff = ftab[(vv + 1) << 8] - ftab[vv << 8];
        Int32 prev_index, prev_value, prev_ftab_diff;

        // Unroll the while loop into a for loop with indirect access via precomputed indices
        for (; j > h - 1; j -= h) {
            prev_index = j - h;
            prev_value = runningOrder[prev_index];
            prev_ftab_diff = ftab[(prev_value + 1) << 8] - ftab[prev_value << 8];

            if (prev_ftab_diff <= key_ftab_diff) break;

            runningOrder[j] = prev_value;
        }
        runningOrder[j] = vv;
    }
}
