#include <stdio.h>

#include <inttypes.h>

extern int patlen;
extern int skip[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= (127 * 2 + 1); ++i)
    for (int k = 0; k < 1; ++k)
        skip[i] = patlen;
}
