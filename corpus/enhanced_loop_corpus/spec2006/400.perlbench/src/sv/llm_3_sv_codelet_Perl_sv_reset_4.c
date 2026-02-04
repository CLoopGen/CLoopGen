#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern I32 max;
extern char todo[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal from max down to i
    I32 start = i;
    for (i = max; i >= start; i--) {
        todo[i] = 1;
    }
}
