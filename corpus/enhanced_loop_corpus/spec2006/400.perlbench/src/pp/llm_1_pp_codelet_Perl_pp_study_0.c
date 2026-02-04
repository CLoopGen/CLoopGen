#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 ch;
extern I32 *sfirst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ch = 16; ch; --ch)
        for (I32 inner = 16; inner; --inner)
            *sfirst++ = -1;
}
