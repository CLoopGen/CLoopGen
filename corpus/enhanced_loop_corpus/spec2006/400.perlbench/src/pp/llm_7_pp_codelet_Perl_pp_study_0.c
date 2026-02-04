#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 ch;
extern I32 *sfirst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 i;
    for (i = 0; i < 256; ++i) {
        *(sfirst + i) = -1;
    }
    ch = 0;
}
