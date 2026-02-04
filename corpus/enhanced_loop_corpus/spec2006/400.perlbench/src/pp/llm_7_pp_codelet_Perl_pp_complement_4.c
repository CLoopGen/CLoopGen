#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef int I32;

extern U8 *tmps;
extern I32 anum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    U8 *base = tmps;
    for (I32 i = 0; i < anum && (unsigned long)(base + i) % sizeof(long); i++) {
        *(base + i) = ~*(base + i);
        if (i + 1 < anum && (unsigned long)(base + i + 1) % sizeof(long)) {
            *(base + i + 1) = ~*(base + i + 1);
            i++;
        }
    }
    tmps += anum;
    anum = 0;
}
