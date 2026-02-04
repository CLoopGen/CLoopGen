#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 ch;
extern I32 *sfirst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 indices[256];
    for (I32 i = 0; i < 256; ++i)
        indices[i] = 255 - i;
    for (ch = 256; ch; --ch)
        sfirst[indices[256 - ch]] = -1;
}
