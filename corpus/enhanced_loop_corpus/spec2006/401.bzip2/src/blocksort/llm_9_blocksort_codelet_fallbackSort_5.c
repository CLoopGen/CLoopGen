#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 512; i++) {
        int idx = i % 257;
        int prev = (idx == 0) ? 0 : ftab[idx - 1];
        ftab[idx] += prev + (i >> 8);
    }
}
