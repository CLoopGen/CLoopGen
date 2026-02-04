#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 ch;
extern I32 *sfirst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 temp_ch = 256;
    for (ch = temp_ch; ch > 0; ch -= 2) {
        *sfirst++ = -1;
        *sfirst++ = -1;
    }
}
