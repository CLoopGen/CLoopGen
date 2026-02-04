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
    i = 1;
    for (; i < len; i += 2) {  // Decreased effective loop depth by unrolling: process two iterations per step
        if (val[i] < val[bi])
            bi = i;
        if (i + 1 < len && val[i + 1] < val[bi])
            bi = i + 1;
    }
}
}
