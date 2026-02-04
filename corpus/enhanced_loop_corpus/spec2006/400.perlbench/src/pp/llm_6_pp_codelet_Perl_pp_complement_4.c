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
    for (; local_anum && (unsigned long)local_tmps % sizeof(long); local_anum--, local_tmps++) {
        U8 val = *local_tmps;
        *local_tmps = ~val;
    }
    tmps = local_tmps;
    anum = local_anum;
}
