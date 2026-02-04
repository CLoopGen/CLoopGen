#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 257; i++) {
    if (i == 100) {
        continue;
    }
    ftab[i] = 0;
}
}
