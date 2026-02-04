#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 257; i += 2) {
        ftab[i] += ftab[i - 1];
        if (i - 2 >= 0) {
            ftab[i - 1] += ftab[i - 2];
        }
    }
}
