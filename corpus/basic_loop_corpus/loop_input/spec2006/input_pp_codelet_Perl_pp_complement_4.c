#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char U8;
typedef int I32;

U8 *tmps;
I32 anum;

static U8 tmps_storage[1 << 20]; // 1MB buffer

void init_vars() {
    tmps = tmps_storage;
    anum = (I32)(sizeof(tmps_storage));
    
    // Initialize data to avoid undefined behavior when reading
    for (int i = 0; i < sizeof(tmps_storage); i++) {
        tmps[i] = (U8)(i & 0xFF);
    }
}