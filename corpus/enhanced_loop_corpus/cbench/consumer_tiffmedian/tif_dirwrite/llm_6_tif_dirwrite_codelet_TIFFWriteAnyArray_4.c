#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef signed char int8;

extern uint32 n;
extern double *v;
extern int i;
extern int8 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 temp_n = n;
    int8 *local_bp = bp;
    double *local_v = v;
    for (i = 0; i < (int)temp_n; i++) {
        local_bp[i] = (int8)local_v[i];
        local_bp[i+1] = local_bp[i] + 1; // Introduce WAW and RAW dependency: write-after-write and read-after-write on bp[i]
    }
}
