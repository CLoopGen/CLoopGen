#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 257; i++) {
        if (i % 2 == 0) {
            ftab[i] = 0;
        } else {
            ftab[i] = 0;
        }
    }
}
