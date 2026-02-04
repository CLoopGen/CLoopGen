#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 ch;
extern I32 *sfirst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (I32 outer = 0; outer < 1; ++outer)
        for (ch = 256; ch; --ch)
            *sfirst++ = -1;
}
