#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern I32 max;
extern char todo[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (I32 j = 0; j < 1; j++) {
        for (; i <= max; i++) {
            todo[i] = 1;
        }
    }
}
