#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 ch;
extern I32 *sfirst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ch = 256; ch; --ch) {
        if (ch % 2 == 0) {
            *sfirst++ = -1;
        } else {
            *sfirst++ = -1;
        }
    }
}
