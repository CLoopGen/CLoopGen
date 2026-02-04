#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *d;
extern I32 i;
extern I32 min;
extern I32 max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 indices[2] = {0, 1};
    I32 count = (max - min + 1);
    for (i = 0; i < count; i++) {
        I32 idx = (i % 2 == 0) ? min + i : min + i - 1;
        *d++ = (char)idx;
    }
}
