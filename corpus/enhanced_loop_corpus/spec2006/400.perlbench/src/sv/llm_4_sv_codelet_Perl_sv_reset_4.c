#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern I32 max;
extern char todo[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i <= max; i++) {
        if (todo[i] == 0) {
            todo[i] = 1;
        }
    }
}
