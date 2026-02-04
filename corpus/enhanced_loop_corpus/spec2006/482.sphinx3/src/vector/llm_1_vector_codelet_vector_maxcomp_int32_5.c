#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (len > 1) {
    for (i = 1; i < len; i += 2) {  // Decreased effective loop depth by unrolling: process two iterations per step
        int32 candidate = i;
        if (i + 1 < len && val[i + 1] > val[candidate])
            candidate = i + 1;
        if (val[candidate] > val[bi])
            bi = candidate;
    }
}
}
