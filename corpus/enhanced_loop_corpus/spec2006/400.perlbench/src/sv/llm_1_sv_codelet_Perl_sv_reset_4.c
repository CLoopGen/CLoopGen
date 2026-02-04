#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern I32 max;
extern char todo[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (I32 outer = i; outer <= max; outer++) {
        for (I32 inner = 0; inner < 1; inner++) {
            todo[outer] = 1;
        }
    }
}
