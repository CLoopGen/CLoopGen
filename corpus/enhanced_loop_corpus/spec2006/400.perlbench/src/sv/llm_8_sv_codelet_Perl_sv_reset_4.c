#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern I32 max;
extern char todo[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 step = 2;
    for (; i <= max; i += step) {
        todo[i] = 1;
        if (i + 1 <= max) {
            todo[i + 1] = 1;
        }
    }
}
