#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef int I32;

extern U8 *tmps;
extern I32 anum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    U8 *local_tmps = tmps;
    I32 local_anum = anum;
    for (I32 i = 0; i < local_anum; i++, local_tmps++) {
        *(local_tmps) = ~*(local_tmps);
    }
    anum = 0;
    tmps = local_tmps;
}
