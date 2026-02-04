#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef int I32;

extern U8 *tmps;
extern I32 anum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; anum >= 4; anum -= 4, tmps += 4) {
        *tmps = ~*tmps;
        *(tmps + 1) = ~*(tmps + 1);
        *(tmps + 2) = ~*(tmps + 2);
        *(tmps + 3) = ~*(tmps + 3);
    }
    for (; anum && (unsigned long)tmps % sizeof(long); anum--, tmps++)
        *tmps = ~*tmps;
}
