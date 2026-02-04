#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *d;
extern I32 i;
extern I32 min;
extern I32 max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 stride = 2;
    for (i = min; i <= max; i += stride) {
        *d++ = (char)i;
        if (i + 1 <= max) {
            *d++ = (char)(i + 1);
        }
    }
}
