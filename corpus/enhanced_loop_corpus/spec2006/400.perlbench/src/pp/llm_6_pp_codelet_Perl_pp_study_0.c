#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 ch;
extern I32 *sfirst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 temp = -1;
    for (ch = 256; ch; --ch) {
        *sfirst = temp;
        sfirst++;
    }
}
